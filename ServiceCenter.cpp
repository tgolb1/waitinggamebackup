#include "ServiceCenter.h"

using namespace std;

ServiceCenter::ServiceCenter(){}

ServiceCenter::ServiceCenter(string inputFile){
    queue = new ListQueue<Customer>();
    openWindows(inputFile);
    tick = 0;
    simulate();
}

ServiceCenter::~ServiceCenter(){} //TODO: garbage collect

void ServiceCenter::openWindows(string inputFile){
    inFile.open(inputFile);
    if(!inFile.is_open()){
        std::cout << "\nFile not found. Ensure file path and name are valid and try again.\n" << endl;
        exit(1);
    }
    int temp;
    inFile >> temp; 
    registrar = new Office(temp);
    inFile >> temp;
    cashier   = new Office(temp);
    inFile >> temp;
    finAid    = new Office(temp);
}

void ServiceCenter::simulate(){
    Customer *curr;
    int rT, cT, fT; //registrarTime, cashierTime, etc
    char a, b, c; //order of windows visited
    tick = 1;

    if(!(inFile >> nextTime)){ //check if step 1 occurs
        inFile.close();
        return;
    }

    while(true){ //iterate
        if (nextTime == tick) { //if the time of the next customers arriving == clock tick 
            //read in customers
            inFile >> customers;
            for (int i = 0; i < customers; ++i){
                inFile >> rT >> cT >> fT >> a >> b >> c;
                curr = new Customer(rT, cT, fT, a, b, c);
                if (a == 'R') {
                    registrar->enqueue(*curr);
                } else if (a == 'C') {
                    cashier->enqueue(*curr);
                } else if (a == 'F') {
                    finAid->enqueue(*curr);
                } else {
                    cout << "invalid office option. terminating program." << endl;
                    exit(1);
                }
            }
            if(!(inFile >> nextTime)){
                inFile.close();
                break;
            }
        }
        tick++;
    }


    cout << "~ ~ Registrar queue ~ ~" << endl;

    string s;
    while (!(registrar->lq->isEmpty())){
        s = registrar->lq->dequeue().toString();
        cout << s;
    }

    cout << "~ ~ Cashier queue ~ ~" << endl;

    while (!(cashier->lq->isEmpty())){
        s = cashier->lq->dequeue().toString();
        cout << s;
    }

    cout << "\n\n~ ~ Financial aid queue ~ ~" << endl;

    while (!(finAid->lq->isEmpty())){
        s = finAid->lq->dequeue().toString();
        cout << s;
    }
    cout << "\n\n";
}
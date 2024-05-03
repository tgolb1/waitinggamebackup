#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(){}

ServiceCenter::ServiceCenter(string inputFile){
    queue = new ListQueue<Customer>();
    openWindows(inputFile);
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
    int rT, cT, fT;
    char a, b, c;

    while(true){
        if(!(inFile >> curTime)){
            inFile.close();
            break;
        }
        setTime(curTime);
        inFile >> customers;
        cout << "\n\n\nCustomers arriving: " << customers << endl;
        for (int i = 0; i < customers; ++i){
            inFile >> rT >> cT >> fT >> a >> b >> c;
            //cout << rT << cT << fT << endl;
            curr = new Customer(rT, cT, fT, a, b, c);
            cout << "\n------\nCustomer Added:\n\n" << curr->toString() << endl;
        }
    }
}

void ServiceCenter::setTime(int t){
    curTime = t;
}
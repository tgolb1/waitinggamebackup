#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(){}

ServiceCenter::ServiceCenter(string inputFile){
    queue = new ListQueue<Customer>();
    openWindows(inputFile);
    inFile >> curTime; 
    setTime(curTime);
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
            break;
        }
        inFile >> customers;
        for (int i = 0; i < customers; ++i){
            inFile >> rT >> cT >> fT >> a >> b >> c;
            curr = new Customer(rT, cT, fT, a, b, c);
            cout << "\n------\nCustomer Added:\n\n" << curr->toString() << endl;
        }
    }
}

void ServiceCenter::setTime(int t){
    curTime = t;
}
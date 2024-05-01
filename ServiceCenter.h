#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include "ListQueue.h"
#include "Office.h"
#include "Customer.h"

#include <fstream>
#include <string>

using namespace std;

class ServiceCenter {
    public:
        ServiceCenter();
        ServiceCenter(string inputFile);
        ~ServiceCenter();
        void step();
    
    private:
        int curTime;
        int customers;
        Office *registrar;
        Office *cashier;
        Office *finAid;
        ifstream inFile;
        ListQueue<Customer> *queue;
        int windowsOpen[];
};

#endif

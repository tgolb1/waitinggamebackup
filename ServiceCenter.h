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
        void openWindows(string inputFile);
        void simulate();
    
    private:
        Office *registrar;
        Office *cashier;
        Office *finAid;
        int nextTime;
        int customers;
        ifstream inFile;
        ListQueue<Customer> *queue;
        int tick;
};

#endif

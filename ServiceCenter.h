#ifndef SERVICECENTER_H
#define SERVICECENTER_H

#include "ListQueue.h"
#include "Office.h"

class ServiceCenter {
    public:
        ServiceCenter();
        ~ServiceCenter();
    
    private:
        int curTime;
        Office *registrar;
        Office *cashier;
        Office *finAid;
        int 
}

#endif
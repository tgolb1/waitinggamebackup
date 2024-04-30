#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

class Customer {
    public:
        Customer();
        Customer(int arrivalTime, int serviceTimes[]); // {registrar, cashier, finAid}
        ~Customer();
    
    private:
        int arrivalTime;
        int regTime;
        int casTime;
        int finTime;

}

#endif

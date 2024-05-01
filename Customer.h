#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

class Customer {
    public:
        Customer();
        Customer(int serviceTimes[], char windowOrder[]); // service times: {registrar, cashier, finAid}
        ~Customer();
    
    private:
        int regTime;
        int casTime;
        int finTime;
        char win1; //window 1
        char win2; //window 2
        char win3; //window 3

};

#endif

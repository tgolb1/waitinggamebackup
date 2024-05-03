#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer {
    public:
        Customer();
        Customer(int rT, int cT, int fT, char a, char b, char c);
        ~Customer();
        string toString();
    
    private:
        int regTime;
        int casTime;
        int finTime;
        char win1; //window 1
        char win2; //window 2
        char win3; //window 3

};

#endif

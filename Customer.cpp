#include "Customer.h"

Customer::Customer(){}

Customer::Customer(int serviceTimes[], char windowOrder[]) {
    regTime = serviceTimes[0];
    casTime = serviceTimes[1];
    finTime = serviceTimes[2];
    win1 = windowOrder[0];  //window 1, etc
    win2 = windowOrder[1];
    win3 = windowOrder[2];
}

Customer::~Customer(){}

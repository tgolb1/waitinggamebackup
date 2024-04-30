#include "Customer.h"

Customer::Customer(){
    arrivalTime = 0;
}

Customer::Customer(int arrivalTime, int serviceTimes[]) {
    this->arrivalTime = arrivalTime;
    regTime = serviceTimes[0];
    casTime = serviceTimes[1];
    finTime = serviceTimes[2];
}

Customer::~Customer(){}

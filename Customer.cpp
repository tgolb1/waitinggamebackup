#include "Customer.h"

Customer::Customer(){}

Customer::Customer(int rT, int cT, int fT, char a, char b, char c) {
    regTime = rT; //registrar time
    casTime = cT; //cashier time
    finTime = fT; //finAid time
    win1 = a;  //window 1, etc
    win2 = b;
    win3 = c;
}

Customer::~Customer(){}

string Customer::toString(){
    return ("rT cT fT\n" + to_string(regTime) + "  " + to_string(casTime) + "  " + to_string(finTime) + "\n\nwin1 win2 win3\n" + (win1) + "    " + (win2) + "    " + (win3));
}

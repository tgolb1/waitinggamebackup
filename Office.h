#ifndef OFFICE_H
#define OFFICE_H

#include "Window.h"
#include "ListQueue.h"
#include "Customer.h"

#include <iostream>

class Office {
    public:
        Office();
        Office(int numWindows);
        ~Office();
        void enqueue(Customer c);
        void assignWindow(Customer c);
        void update();
        ListQueue<Customer> *lq;

    private:
        int numWindows;
        Window *windows[];
};



#endif

#ifndef WINDOW_H
#define WINDOW_H

#include "Customer.h"
#include "ListQueue.h"

class Window {
    public:
        Window();
        ~Window();
        void service(Customer c);
        void updateWindow();

        bool isOpen;
        int idleTime;
        int serviceTime;
        int timeConsumed;
        ListQueue<Customer> *line;

};

#endif
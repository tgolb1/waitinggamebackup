#ifndef WINDOW_H
#define WINDOW_H

#include "Customer.h"

class Window {
    public:
        Window();
        ~Window();
        void service(Customer c);

        bool isOpen;
        int idleTime;
        int serviceTime;
        int timeConsumed;

};

#endif
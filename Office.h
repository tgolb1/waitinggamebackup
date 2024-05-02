#ifndef OFFICE_H
#define OFFICE_H

#include "Window.h"
#include <iostream>

class Office {
    public:
        Office();
        Office(int numWindows);
        ~Office();

    private:
        int numWindows;
        Window *windows[];
};



#endif

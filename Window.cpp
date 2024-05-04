#include "Window.h"

Window::Window(){
    isOpen = true;
    idleTime = 0;
    timeConsumed = 0;
}


Window::~Window(){
    delete line;
}

void Window::service(Customer c){
    line->enqueue(c);
    if (c.curWindow == 'R'){
        cout << "at the registrar!" << endl;
    } else {
        cout << "at another window!" << endl;
    }
    isOpen = false;
    serviceTime = 1; //todo getOfficeTimeNeeded()
}

void Window::updateWindow(){
    line->peek().update();
}
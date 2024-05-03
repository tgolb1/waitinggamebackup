#include "Window.h"

Window::Window(){
    isOpen = true;
    idleTime = 0;
    timeConsumed = 0;
}


Window::~Window(){

}

void Window::service(Customer c){
    isOpen = false;
    serviceTime = 1; //todo getOfficeTimeNeeded()
}
#include "Office.h"
#include "Customer.h"

Office::Office() {
    cout << "Office must have at least 1 window" << endl;
    exit(1);
}

Office::Office(int numWin) {
    numWindows = numWin;
    lq = new ListQueue<Customer>();
    for (int i = 0; i < numWindows; ++i){
        windows[i] = new Window();
    }
}

Office::~Office() {}

void Office::enqueue(Customer c){
    lq->enqueue(c);
    assignWindow(c);
}

void Office::assignWindow(Customer c){
    for(int i = 0; i < numWindows; ++i){
        if ((windows[i]->isOpen)){
            windows[i]->service(c);
        }
    }
}

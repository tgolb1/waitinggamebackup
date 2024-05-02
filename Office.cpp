#include "Office.h"

Office::Office() {
    numWindows = 1; //by default
}

Office::Office(int numWin) {
    for (int i = 0; i < numWin; ++i){
        windows[i] = new Window();
    }
}

Office::~Office() {}

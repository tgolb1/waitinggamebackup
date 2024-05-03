#include "ServiceCenter.h"

int main(){
    ServiceCenter *sc = new ServiceCenter("testInput.txt");
    delete sc;
    return 0;

}
#include "ServiceCenter.h"

int main(int argc, char **argv){
    ServiceCenter *sc = new ServiceCenter(argv[1]);
    delete sc;
    return 0;

}
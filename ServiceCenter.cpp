#include "ServiceCenter.h"

ServiceCenter::ServiceCenter(){
    queue = new ListQueue<Customer>();
}

ServiceCenter::ServiceCenter(string inputFile){
    string line;
    inFile.open(inputFile);

    if (!inFile.is_open()){
        std::cout << "\nFile not found. Ensure file path and name are correct and try again.\n" << endl;
        exit(1);
    }

    for(int i = 0; i < 3; ++i){ //first 3 lines are windows open
        getline(inFile, line);
        windowsOpen[i] = stoi(line); //[0],[1],[2] = registrar, cashier, financialAid (respectively)
    }
    
    registrar = new Office(windowsOpen[0]);
    cashier   = new Office(windowsOpen[1]);
    finAid    = new Office(windowsOpen[2]);

    step();
}

ServiceCenter::~ServiceCenter(){} //TODO: garbage collect

void ServiceCenter::step(){
    try {
        int times[3]; //times in each window
        char windows[3]; //window order
        while(true){
            if (!(inFile >> customers)){
                cout << "Error reading file!" << endl;
                return;
            }
            for(int i = 0; i < customers; ++i){
                if (!(inFile >> times[0] >> times[1] >> times[2] >> windows[0] >> windows[1] >> windows[2])){
                    cout << "Error reading file!" << endl;
                }
                queue->enqueue(Customer(times, windows)); //throw students on a queue
            }
        }

        //dequeue into windows?


    } catch(exception& e) {
        cout << "Exception occured: " << e.what() << endl;
    }
}
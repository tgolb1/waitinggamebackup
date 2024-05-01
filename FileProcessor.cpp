/*
#include "FileProcessor.h"

using namespace std;

FileProcessor::FileProcessor(){

}
FileProcessor::FileProcessor(string inputFile){
    string line;
    int i = 0;
    ifstream inFile(inputFile);

    if (!inFile.is_open()){
        cout << "\nFile not found. Ensure file path and name are correct and try again.\n" << endl;
        exit(1);
    }

    for(int i = 0; i < 3; ++i){ //first 3 lines are windows open
        getline(inFile, line);
        windowsOpen[i] = stoi(line); //[0],[1],[2] = registrar, cashier, financialAid respectively
    }

    getline(inFile, customers);


}
FileProcessor::~FileProcessor(){}

void FileProcessor::step(){

}
*/
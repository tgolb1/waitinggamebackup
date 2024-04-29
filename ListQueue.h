#ifndef GENQUEUE_H
#define GENQUEUE_H

#include <iostream>
#include <exception>

using namespace std;

//generic double linked-list based queue
template <typename T>
class ListQueue {
    public:
        ListQueue(); //default constructor
        ListQueue(int maxSize); //overload constructor
        ~ListQueue();

        //core fns
        void insert(t d); //enqueue
        t remove(); //dequeue

        //aux/helper fns
        T peek();
        bool isFull();
        bool isEmpty();
        unsigned int getSize(); //unsigned = nonnegative
        void printArray();


    private:
        int mSize;
        unsigned int front;
        unsigned int rear;
        unsigned int numElements;
        T *myQueue;

};

template <typename T>
ListQueue<T>::ListQueue(){
    mSize = 64;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new T[mSize];
}

template <typename T>
ListQueue<T>::ListQueue(int maxSize){
    mSize = maxSize;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new T[mSize];
}

template <typename T>
ListQueue<T>::~ListQueue(){
    delete[] myQueue;
}

void ListQueue<T>::insert(T d) {
    if (isFull()){
        throw runtime_error("queue is full");
    }

    myQueue[rear++] = d;
    numElements++; 
}

template <typename T>
T ListQueue<T>::remove() {
    if (isEmpty()){
        throw runtime_error("queue is empty");
    }

        T c = NULL;
        myQueue[front++] = c;
        numElements--;
        return c;
}

template <typename T>
T ListQueue<T>::peek() {
        if (isEmpty()){
        throw runtime_error("queue is empty");
    }
    return myQueue[front];
}

template <typename T>
bool ListQueue<T>::isFull(){
    return (numElements == mSize);
}

template <typename T>
bool ListQueue<T>::isEmpty(){
    return (numElements == 0);
}

template <typename T>
unsigned int ListQueue<T>::getSize(){
    return numElements;
}

template <typename T>
void ListQueue<T>::printArray(){
        cout << endl << endl;

        cout << "FRONT: " << front << endl;
        cout << "REAR: " << rear << endl;
        cout << "NUM ELEMENTS: " << numElements << endl;
    
    for(int i = 0; i < mSize; ++i) {
        cout << " Q[" << i << "]: " << myQueue[i];
        if (i<mSize-1){
            cout << " |";
        }
    }
    cout << endl << endl;
}


#endif
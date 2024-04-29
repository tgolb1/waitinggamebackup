#ifndef LISTQUEUE_H
#define LISTQUEUE_H

#include "DblList.h"

template <typename T>
class ListQueue{
    public:
        ListQueue();
        ~ListQueue();
        void enqueue(T data);
        T dequeue();
        T peek();
        void printQueue();

    private:
        bool isEmpty();
        int getSize();
        DblList<T> *list;
};

template <typename T>
ListQueue<T>::ListQueue(){
    list = new DblList<T>();
}

template <typename T>
ListQueue<T>::~ListQueue(){
    delete list;
}

template <typename T>
void ListQueue<T>::enqueue(T data){
    list->insertBack(data);
}

template <typename T>
T ListQueue<T>::dequeue(){
    if (isEmpty()){
        throw runtime_error("Queue is empty");
    }
    return list->removeFront();
}

template <typename T>
T ListQueue<T>::peek(){
    if (isEmpty()){
        throw std::runtime_error("Queue is empty");
    }
    return list->front->data;
}

template <typename T>
bool ListQueue<T>::isEmpty(){
    return list->isEmpty();
}

template <typename T>
int ListQueue<T>::getSize(){
    return list->getSize();
}

template <class T>
void ListQueue<T>::printQueue(){
    list->printList(false);
}

#endif

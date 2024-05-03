#ifndef DBLLIST_H
#define DBLLIST_H

#include "ListNode.h"

//templated doubly linked list with pointers to next and prev

template <class T>
class DblList{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;
    public:
        DblList();
        ~DblList();

        void insertFront(T d);
        void insertBack(T d);
        T removeFront();
        T removeBack();
        T removeNode(T value); //method for removing node not the front or the back
        T find(T value); //this is identical to search/find in a SingleLinkedList
        bool isEmpty();
        unsigned int getSize();

        void printList(bool printLink);
};


template <class T>
DblList<T>::DblList(){
    //instantiate empty linked list
    front = NULL;
    back = NULL;
    size = 0;
}

template <class T>
DblList<T>::~DblList(){
    ListNode<T> *node = front;
    ListNode<T> *nodeToBeDeleted = front;
    while (node != NULL){
        nodeToBeDeleted = node->next;
        delete node;
        node = nodeToBeDeleted;
    }
    front = NULL;
    back = NULL;
    size = 0;

}

template <class T>
void DblList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    }
    else{
        //not an empty list
        node->next = front;
        front->prev = node;
    }
    front = node;
    ++size;
}

template <class T>
void DblList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    }
    else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    ++size;
}

template <class T>
T DblList<T>::removeFront(){

    if(isEmpty()){
        throw runtime_error("list is empty");
    }

    ListNode<T> *temp = front;

    if(front->next == NULL){
        back = NULL;
    }
    else{
        //more than one node
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    T data = temp->data;
    --size;
    delete temp;

    return data;
}

template <class T>
T DblList<T>::removeBack(){

    if(isEmpty()){
        throw runtime_error("list is empty");
    }

    ListNode<T> *temp = back;

    if(back->prev == NULL){
        front = NULL;
    }else{
        //more than one node
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    T data = temp->data;
    --size;
    delete temp;

    return data;
}

template <class T>
T DblList<T>::find(T value){
     int pos = -1; // variable to idetify position of node with matching value
    ListNode<T> *curr = front;

    while(curr != NULL){
        ++pos;
        if(curr->data == value)
            break;
        
        curr = curr->next;
    }
    if(curr == NULL)
        pos = -1;

    return pos;
}

template <class T>
T DblList<T>::removeNode(T value){

    if(isEmpty()){
        throw runtime_error("list is empty");
    }

    ListNode<T> *curr = front;
    while(curr->data != value){
        curr = curr->next;

        if(curr == NULL)
            return -1;
    }

    //if we get here, then we found the node to be deleted
    // so let's proceed

    if(getSize() == 1){
        front = NULL;
        back = NULL;
    }
    else if(curr == front){
        front = curr->next;
        front->prev = NULL;
    }
    else if(curr == back){
        back = curr->prev;
        back->next = NULL;
    }
    else{
        //current is between front and back
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    curr->next = NULL;
    curr->prev = NULL;
    T temp = curr->data;
    --size;
    delete curr;
    return temp;
}

template <class T>
unsigned int DblList<T>::getSize(){
    return size;
}

template <class T>
bool DblList<T>::isEmpty(){
    return (size == 0);
}

template <class T>
void DblList<T>::printList(bool printLink)
{
    ListNode<T> *curr = front;
    while(curr != 0){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
       if(printLink)
        cout << "[ PREV: "<< curr->prev << " || " << curr->data << " || NEXT: "<< curr->next << " ] ";
      else
        cout << "[ " << curr->data << " ] ";

       curr = curr->next;
       if(curr != 0){
         cout << " <==> ";
       }
    }
    cout << endl;
}

#endif
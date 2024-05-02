#include "ListQueue.h"
#include "ServiceCenter.h"

int main(){

    ServiceCenter *sc = new ServiceCenter("testInput.txt");

    delete sc;
    return 0;
/*
    ListQueue<int> *lq = new ListQueue<int>();

    lq->enqueue(1);
    lq->enqueue(2);
    lq->enqueue(3);
    lq->enqueue(4);
    lq->enqueue(5);
    lq->enqueue(6);
    lq->enqueue(7);

    lq->printQueue();


    lq->dequeue();
    lq->dequeue();
    lq->dequeue();


    lq->printQueue();


    return 0;
*/

}
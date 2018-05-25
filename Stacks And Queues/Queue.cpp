/*
 * Author: Gary Allen
 * Date: 03/18/2018
 * Assignment: Program #4 - Stacks & Queues
 * File: main.cpp
 * Description: Implements the methods of the Queue class for usage
 */
#include "Queue.h"

//adds a new node with the specified data to the back of the Queue
void Queue::AddQ(QueueElement x) {
    qnode *Q = new qnode;
    Q->data = x;
    Q->next = NULL;

    if (Empty() == true) {
        myFront = myBack = Q;

    } else {
        myBack->next = Q;
        myBack = Q;
    }
}

//returns true if the queue is empty and false otherwise
bool Queue::Empty() {
    if (myFront == NULL) {
        return true;
    }
    return false;
}

//returns true if there is a front node and false otherwise; also retrieves the data from the front
bool Queue::Front(QueueElement &x) {
    if (!Empty()) {
        x = myFront->data;
        return true;
    }
    return false;
}

//removes the first item that was placed in the queue
void Queue::RemoveQ() {
    if (Empty() == true) {
        return;
    }
    qnode *p;
    p = myFront;
    myFront = myFront->next;
    delete p;
}

//initializes the Queue to empty
Queue::Queue() {
    myFront = NULL;
    myBack = NULL;
}
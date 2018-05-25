/*
 * Author: Gary Allen
 * Date: 03/18/2018
 * Assignment: Program #4 - Stacks and Queues
 * File: main.cpp
 * Description: This file has all the necessary methods and variables for the Queue class
 */
#include <iostream>
#include "Card.h"

using namespace std;
typedef struct Card QueueElement;
struct qnode {
    QueueElement data;
    qnode *next;
};

class Queue {
public:
    Queue(); // create an empty Queue
    bool Empty(); //return true if Queue is empty, otherwise return false
    void AddQ(QueueElement x); //add a new value to the back of the Queue
    bool Front(QueueElement &x); //retrieve the data at the front of the Queue
    void RemoveQ(); //remove the value at the front of the Queue

private:
    qnode *myFront; //pointer to the front of the queue
    qnode *myBack; //pointer to the back of the queue
};

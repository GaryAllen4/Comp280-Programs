/*
 * Author: Gary Allen
 * Date: 03/18/2018
 * Assignment: Program #4 - Stacks & Queues
 * File: Card.cpp
 * Description: This file implements all methods for the Stack class
 */
#include "Stack.h"

bool Stack::empty() {
    if (myTop == NULL) {
        return true;
    } else {
        return false;
    }
}

void Stack::pop() {
    node *p; //change p
    if (empty() == false) {
        p = myTop;
        myTop = myTop->next;
        delete p;

    }

}

void Stack::push(StackElement x) {
    node *node1 = new node;
    node1->data = x;
    node1->next = myTop;
    myTop = node1;
}

bool Stack::top(StackElement &x) {
    if (empty() == false) {
        x = myTop->data;
        return true;
    } else {
        return false;
    }
}

Stack::Stack() {
    myTop = new node;
    myTop = NULL;

}
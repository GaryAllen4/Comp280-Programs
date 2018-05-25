/*
 * Author: Gary Allen
 * Date: 03/18/2018
 * Assignment: Program #4 - Stacks & Queues
 * File: main.cpp
 * Description: This file has all the necessary methods and variables for the Stack class
 */
#include <iostream>
#include "Card.h"

using namespace std;
typedef struct Card StackElement;
struct node {
    StackElement data;
    node *next;
};

class Stack {
public:
    Stack(); // create an empty stack
    bool empty(); //return true if stack is empty, otherwise return false
    void push(StackElement x); //add a new value to the top of the stack
    bool top(StackElement &x); //retrieves the data that is at the top of the stack
    void pop(); //removes the value at the top of the stack

private:
    node *myTop; //pointer to the top of the stack
};
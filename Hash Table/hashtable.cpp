/*
 * Author: Gary Allen
 * Date: 04/22/2018
 * Assignment: Program #6 - Hash Table
 * File: hashtable.cpp
 * Description: This file implements(gives instructions) all the methods for the hashtable class
 */
// Created by Gary on 4/11/2018.
//
using namespace std;

#include<iostream>
#include "hashtable.h"

void hashtable::Insert(int value) {
    // int value to hold the location to put the value after using linear probing
    int location;
//variable to hold the value received from the mod of inserted value with the size of the table
    location = value % size;
    if (table[location] == -1) { //if the location has no values in it
        table[location] = value; //place the value inside the table
        count++; //increments the values in the table
    } else {
        while (table[location] != -1) { //loops through the table to find an open location for the value if its initial location is taken
            location++;
            if (location == size) { //if we have reached the end of the table, go back to the start
                location = 0;
            }
        }
        table[location] = value;
        count++;
    }
}
//sets default values of the hash table
hashtable::hashtable(int size) {
    this->size = size;
    this->count = 0;
    //create the hash table of the specified size
    table = new int[size];
    //instantiate each location to 0, which means nothing there
    for (int i = 0; i < size; i++) {
        table[i] = -1;
    }
}
//display every location in the hash table
void hashtable::display() {
    int counter = 0; //counter used to show the values at each location of the table
    for (int i = 0; i < size; i++) { //loops through the table and prints the data for each index
        if (table[i] == -1) {
            cout << counter << "- "<<endl;
            counter++;
        } else {
            cout << counter << "-" << table[i]<<endl;
            counter++;
        }
    }
}
//used to tell if the hash table is full
bool hashtable::Isfull() {
    if (count == size) { //the table is full if the amount of values equals the size of the table
        return true;
    }
    return false;
}
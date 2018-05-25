/*
 * Author: Gary Allen
 * Date: 04/22/2018
 * Assignment: Program #6 - Hash Table
 * File: main.cpp
 * Description: Executes the program using implemented methods and variables
 */
#include <iostream>
#include "hashtable.h"

using namespace std;

int main() {
    //used for the user's choice from the menu
    int optionNumber;
    //used to set the size of the hash table
    int size;

    cout << "What size would you like the hash table to be?" << endl;
    cin >> size;
//create an object of the hashtable class to execute the methods
    hashtable htable(size);

    bool programRunning = true; //controls how long the loop runs
    while (programRunning) {
        //menu displayed to the user to define the usage
        cout << "HASH TABLE MENU" << endl;
        cout << "1. Insert an integer value into the hash table" << endl;
        cout << "2. Display the hash table" << endl;
        cout << "3. Exit the Program" << endl;
        cin >> optionNumber; //takes in the users input
        if (optionNumber == 1) {
            if (htable.Isfull()) { //if full there is nothing that can be inserted
                cout << "The hash table is now full, you should use option 2 or 3 now" << endl;
            } else {
                int number; //intakes the users input for table size
                cout << "What int value would you like to insert?" << endl;
                cin >> number;
                //if inserted value is an int value
                if (cin.good()) {
                    htable.Insert(number);
                    //if not then alert user
                } else {
                    cout << "WRONG INPUT. INSERT INTEGER VALUES ONLY!" << endl;
                    cin.clear();
                    cin.ignore(sizeof(number), '\n');
                }
            }
        } else if (optionNumber == 2) {
            htable.display();
        } else if (optionNumber == 3) {
            programRunning = false;
        } else {
            cout << "WRONG INPUT!" << endl;
        }
    }

}
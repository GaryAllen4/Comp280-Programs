/*
 * Author: Gary Allen
 * Date: 02/09/2018
 * Assignment: Program #2: Linked List Array
 * File: List.cpp
 * Description: This file contains the implementation for all the methods
 */
#include "List.h"
#include <ctime>
#include <iostream>

using namespace std;

//Method used to give default values to List
List::List() {
    N = 0;
}

//Method used to tell if the empty is empty or not
bool List::isEmpty() {
    if (N == 0) {
        return true;
    } else {
        return false;
    }
}

//Method used to insert a string value at the end of the array and increment the array's size
void List::InsertAtEnd(ElementType x) {
    if (N == MAX) {
        cout << "YOU ARE OUTSIDE OF THE ARRAY'S MAX SIZE";

    } else {
        listArray[N] = x;
        N++;
    }

}

//Method used to display the current list in its reverse order to the user
void List::ReverseDisplay() {
    if (!isEmpty()) {
        cout << "Reverse Display Shown Below: " << endl;
        for (int i = N - 1; i >= 0; i--) { //loops through array and displays every index
            cout << listArray[i] << " ";
            cout << endl;
        }
    } else {
        cout << "The list is currently empty. Select Option 1 to insert some items into the list." << endl;
    }
}

//Method used to display the user's selected location's current string value
void List::GetValueAt(int n) {
    cout << "The value you requested is displayed below: " << endl;
    cout << listArray[n] << endl;

}

//Method used to delete all instances of the user's chosen string value
void List::DeleteAll(ElementType x) {
    //value used to keep track of the current index being evaluated
int index = 0;
    while(index < N) { //while the index is not outside of the array's size
        if (listArray[index] == x) { //if value is found at this index then replace all current indexes with their next index except the last position

            for (int j = index; j < N - 1; j++) {
                listArray[j] = listArray[j + 1];
            }
            N--; //decrement array size
        } else {
            index++; //if value is not found just move on to the next position
        }
    }

}

//Method used to display either all strings, even length strings or odd length strings
void List::Display(string type) {


    if (type == "All") {
        cout << "All Strings in the Current List: " << endl;
        for (int i = 0; i < N; i++) {
            cout << listArray[i] << endl;
        }
    } else if (type == "Even") {
        cout << "All Even Length Strings in the Current List: " << endl;
        for (int i = 0; i < N; i++) {
            if (listArray[i].length() % 2 == 0) { //if remainder of the index value's length divided by two is 0 then it is even, so display it
                cout << listArray[i] << endl;
            }
        }
    } else if (type == "Odd") {
        cout << "All Odd Length Strings in the Current List: " << endl;
        for (int i = 0; i < N; i++) {
            if (listArray[i].length() % 2 == 1) { //if remainder of the index value's length divided by two is 1 then it is odd, so display it
                cout << listArray[i] << endl;
            }
        }
    } else {
        cout << "WRONG INPUT. TRY AGAIN" << endl;
    }

}

//Method used to sort the current list from shortest to longest string
void List::Sort() {
    if (!isEmpty()) {
        //variable to tell if the list is sorted or not
        bool notSorted = true;
        for (int i = 1; (i < N) && notSorted; i++) {
            notSorted = false;
            for (int j = 0; j < N - 1; j++) {
                if (listArray[j].length() > listArray[j + 1].length()) { //if array index length is greater than next position's length, interchange them

                    //variable to store a value to be moved to another position
                    string tempVal = listArray[j];
                    listArray[j] = listArray[j + 1];
                    listArray[j + 1] = tempVal;
                    notSorted = true;
                }
            }
        }
    } else {
        cout << "The list is currently empty. Select Option 1 to insert some items into the list." << endl;
    }
}

//Method used to calculate the median string length of the list
double List::Median() {
    //Must sort the array before the median can be found
    Sort();
    if (N % 2 == 0) { //if the array's length is even
        cout << "The median is: " << (listArray[(N / 2)].length() + listArray[((N / 2) - 1)].length()) / 2.0 << endl; //adds the two closest values int the "middle" of the list and divideds by two to find their median length
    } else { //array length odd
        cout << "The median is: " << listArray[(N / 2)].length() << endl; //outputs the length of the middle value
    }
}

//Method used to randomly shuffle the string values in the list
void List::Shuffle() {
    if (!isEmpty()) {
        srand(time(0));
        for (int i = N - 1; i > 0; i--) {
            int j = rand() % (i); //takes a random value to pick a index within the array

            //variable stores the value temporarily to be transferred to another position
            string temp = listArray[j];
            listArray[j] = listArray[i];
            listArray[i] = temp;
        }
    } else {
        cout << "The list is currently empty. Select Option 1 to insert some items into the list." << endl;
    }
}
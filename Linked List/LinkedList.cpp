/*
 * Author: Gary Allen
 * Date: 02/24/2018
 * Assignment: Program #2: Linked List
 * File: LinkedList.cpp
 * Description: This file implements the given methods and gives instructions
 */
#include <iostream>
#include "LinkedList.h"
#include <ctime>


using namespace std;

//Method used to create an empty list
LinkedList::LinkedList() {
    first = new Node;
    first->data = "";
    first->next = NULL;
}
//function checks to see if list is empty or not
bool LinkedList::isEmpty() {
    if (first->data == "") {
        return true;
    } else {
        return false;
    }
}
//method sorts the current linked list
void LinkedList::Sort() {
    //node to keep track of the current node
    Node *current = first;
    //string to hold the data of the current node
    string tempString;
    //counter used to count the nodes
    double counter = 0;
    //loop through list and count the number of nodes
    while (current != NULL) {
        current = current->next;
        counter++;
    }
    //temporary node to help swap the data of two nodes
    Node *tempNode = first;
    //traverse through list and swap nodes to put data in order shortest to longest
    for (int i = 1; i < counter; i++) {
        for (int j = 0; j < counter - 1; j++) {
            if (tempNode->data.length() > tempNode->next->data.length()) {
                tempString = tempNode->data;
                tempNode->data = tempNode->next->data;
                tempNode->next->data = tempString;

            }
            tempNode = tempNode->next;
        }
        tempNode = first;
    }


}
//method to display the list data in reverse order
void LinkedList::ReverseDisplay() { //correct
    if (isEmpty() == true) {
        cout << "The list is currently empty. Select Option 1 to insert some items into the list." << endl;

    } else {
        //current node
        Node *currently = first;

//traverse through list
        while (currently->next != NULL) {
            currently = currently->next;
        }

        cout << currently->data << endl; //prints out last node data
        //node pointer to node with data that is to be printed out
        Node *tempNode = first;
        while (currently != first) {
            while (tempNode->next != currently) {
                tempNode = tempNode->next;
            }
            cout << tempNode->data << endl;
            currently = tempNode;
            tempNode = first;
        }

    }
}
//method to show the user the string value at the specified location
void LinkedList::GetValueAt(int n) {
    if (isEmpty() == true) {
        cout << "The list is currently empty. Select Option 1 to insert some items into the list." << endl;

    } else {
        //for current node that's in use
        Node *currently = first;
        //traverse through the list
        for (int i = 1; i < n; i++) {
            currently = currently->next;

        }
        //print specified location's data
        cout << currently->data << endl;
    }
}

//Method to display either all, even, or odd string lengths
void LinkedList::Display(string type) { //correct
    if (type == "All") {
        cout << "All Strings in the Current List:" << endl;
        Node *currently = first;

        //traverse through list and print every value
        while (currently->next != NULL) {
            cout << currently->data << endl;
            currently = currently->next;
        }
        cout << currently->data << endl;
    } else if (type == "Odd") {
        cout << "All Odd Length Strings in the Current List:" << endl;
        Node *currently = first;
        //counter for the number of nodes
        int counter = 0;
        //traverses through the list and counts the nodes
        while (currently != NULL) {
            currently = currently->next;
            counter++;
        }

        currently = first;
        //checks the data to see if the value is odd length
        for (int i = 0; i < counter; i++) {
            if (currently->data.length() % 2 == 1) {
                cout << currently->data << endl;
            }
            currently = currently->next;
        }


    } else if (type == "Even") {
        cout << "All Even Length Strings in the Current List:" << endl;
        Node *currently = first;
        //counter for the nodes
        int counter = 0;
        //traverses through the list and counts the nodes
        while (currently != NULL) {
            currently = currently->next;
            counter++;
        }

        currently = first;
        //checks the data to see if the value is even length
        for (int i = 0; i < counter; i++) {
            if (currently->data.length() % 2 == 0) {
                cout << currently->data << endl;
            }
            currently = currently->next;
        }

    } else {
        cout<< "Please use All, Even, or Odd!"<<endl;
    }
}

//method to delete all instances of the specified string value
void LinkedList::DeleteAll(ElementType x) {
    //holds the current node
    Node* currently = first;
    //holds the previous node
    Node* prevNode = first;
    //traverse through the list and delete any nodes with the specified data value
    while(currently != NULL) {
        if(currently->data == x) {
            if(currently == first) {
                first = currently->next;
                delete currently;
                prevNode = first;
                currently = first->next;
            } else {
                prevNode->next=currently->next;
                delete currently;
                currently = prevNode->next;
            }
        } else {
            prevNode=currently;
            currently=currently->next;
        }
    }

}
//method to insert a new node with the provided data
void LinkedList::InsertAtEnd(ElementType x) {
    if (isEmpty() == true) {
        first->data = x;
    } else {
        //current node in the list
        Node *currently = first;
        while (currently->next != NULL) {
            currently = currently->next;
        }
        //new node added to list with new data
        Node *newNode = new Node;
        currently->next = newNode;
        newNode->data = x;
        newNode->next = NULL;

    }
}
//method that first sorts the list and then determines the median value and returns
double LinkedList::Median() { //correct
    Sort();
    if (isEmpty() == true) {
        return 0.0;
    }
//current node being used
    Node *currently = first;
    //to count the nodes
    int counter = 0.0;
    //traverse through list and count nodes
    while (currently != NULL) {
        counter++;
        currently = currently->next;

    }
    //checks to see if the number of nodes is even and then finds the median
    if (counter % 2 == 0) {
        Node *current;
        double stringSecondLength;
        double stringFirstLength;
        current = first;

        for (int i = 0; i < (counter / 2); i++) {
            current = current->next;
        }

        stringSecondLength = current->data.length();
        current = first;

        for (int i = 1; i < (counter / 2); i++) {
            current = current->next;
        }

        stringFirstLength = current->data.length();
        return (stringSecondLength + stringFirstLength) / 2.0;
    } else {
        //the current node used
        Node *current = first;
        //to hold the median value
        double median;
//finds the node in the middle of the list
        for (int i = 0; i < (counter) / 2; i++) {
            current = current->next;
        }

        median = current->data.length();
        return median;
    }

}
//method to shuffle the linked list nodes
void LinkedList::Shuffle() {
    //linked list is sorted
    Sort();
    if (isEmpty() == true) {
        cout << "Nothing to shuffle, enter some values using option 1." << endl;
    }
    //current node being used
    Node *current = first;
    Node *tempNode;
    //holds string value of a node
    string tempString;
    //number of nodes in the list
    int count = 0;
//loops through the list and counts the number of nodes
    while (current != NULL) {
        count++;
        current = current->next;
    }

    tempNode = first;
    //used to access the random node
    Node *randNode = first;
    srand(time(0));
//loops through the list
    for (int i = count - 1; i > 0; i--) {
        //creates a random int value between 0 and count's value + 1
        int random = rand() % (count+1);
//loops to random node
        for (int i = 1; i < random; i++) {
            randNode = randNode->next;
        }
//swaps the two nodes' data values
        tempString = tempNode->data;
        tempNode->data = randNode->data;
        randNode->data = tempString;
        tempNode = tempNode->next;
        randNode = first;
    }

}
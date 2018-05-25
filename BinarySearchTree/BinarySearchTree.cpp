/*
 * Author: Gary Allen
 * Date: 04/04/2018
 * Assignment: Program #5 - Binary Search Tree
 * File: BinarySearchTree.cpp
 * Description: This file implements all the necessary methods and variables for the BinarySearchTree class
 */

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

//creates and set default values for class object
BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

//method to tell if the binary tree is empty
bool BinarySearchTree::empty() {
    if (root == nullptr) {
        return true;
    }
    return false;
}

//method to recursively display the tree's nodes
void BinarySearchTree::Display() {
    Display(root);
}

//method to delete a specified node
void BinarySearchTree::Delete(int courseNum) {
    node *p = root;
    node *q = nullptr;

    while (p != nullptr) {

        if (courseNum == p->courseNumber) {
            if (q == nullptr) {
                if (p->leftchild == nullptr) {
                    root = p->rightchild;
                } else if (p->rightchild == nullptr) {
                    root = p->leftchild;
                } else {
                    node *lefty = p->rightchild;
                    while (lefty->leftchild != nullptr) {
                        lefty = lefty->leftchild;

                    }
                    Delete(lefty->courseNumber);
                    p->courseNumber = lefty->courseNumber;
                    p->counter = lefty->counter;
                }
            } else {
                if (p->leftchild == nullptr) {
                    if (p->courseNumber < q->courseNumber) {

                        q->leftchild = p->rightchild;
                    } else {
                        q->rightchild = p->rightchild;
                    }
                } else if (p->rightchild == nullptr) {
                    if (p->courseNumber < q->courseNumber) {

                        q->leftchild = p->leftchild;
                    } else {
                        q->rightchild = p->leftchild;

                    }
                } else {

                    node *lefty = p->rightchild;
                    while (lefty->leftchild != nullptr) {
                        lefty = lefty->leftchild;

                    }
                    Delete(lefty->courseNumber);
                    p->courseNumber = lefty->courseNumber;
                    p->counter = lefty->counter;
                }
            }
            return;
        }
        q = p;
        if (p->courseNumber > courseNum) {
            p = p->leftchild;
        } else if (p->courseNumber < courseNum) {
            p = p->rightchild;
        }

    }
}

//method to insert a new node with the course and its counter into the tree
void BinarySearchTree::Insert(int courseNum) {
    if (empty()) {
        root = new node;
        root->counter = 1;
        root->courseNumber = courseNum;
        root->leftchild = root->rightchild = nullptr;
        return;
    }
    node *p = root;
    node *q = nullptr;
    while (p != nullptr) { //loop to find the correct location to place the new course number
        q = p;
        if (courseNum == p->courseNumber) {
            p->counter++;
            return;
        } else if (courseNum < p->courseNumber) {
            p = p->leftchild;
        } else {
            p = p->rightchild;
        }
    }
    p = new node;
    p->courseNumber = courseNum;
    p->counter = 1;
    p->leftchild = p->rightchild = nullptr;

    if (root == nullptr)
        root = p;
    else if (courseNum < q->courseNumber)
        q->leftchild = p;
    else
        q->rightchild = p;
    return;
}

//method to tell if the node with the specified course number exists in the tree
bool BinarySearchTree::IsThere(int courseNum) {
    if (empty()) {
        return false;
    } else if (root->courseNumber == courseNum) {
        return true;
    }
    node *currentNode = root;
    while (currentNode->courseNumber != courseNum && currentNode != nullptr) {
        if (courseNum < currentNode->courseNumber) {
            currentNode = currentNode->leftchild;
        } else {
            currentNode = currentNode->rightchild;
        }
    }

    if (currentNode->courseNumber == courseNum) {
        return true;
    }
    return false;
}

//method displays all nodes recursively
void BinarySearchTree::Display(node *p) {
    if (p == NULL)
        return;
    else {
        Display(p->leftchild);
        cout << p->courseNumber << ": " << p->counter << " interested" << endl;
        Display(p->rightchild);
    }
}

//method to delete courses with one student
void BinarySearchTree::DeleteAllOnes() {
    DeleteAllOnes(root);
}

//method to delete courses with one student
void BinarySearchTree::DeleteAllOnes(node *p) {
    if (empty() == false) {
        if (p != NULL) {
            DeleteAllOnes(p->leftchild);
            DeleteAllOnes(p->rightchild);
            if (p->counter == 1) {
                Delete(p->courseNumber);
            }
        }
    }
}
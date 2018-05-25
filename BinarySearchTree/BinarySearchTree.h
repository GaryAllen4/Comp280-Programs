/*
 * Author: Gary Allen
 * Date: 04/04/2018
 * Assignment: Program #5 - Binary Search Tree
 * File: BinarySearchTree.h
 * Description: This file has all the necessary methods and variables for the BinarySearchTree class
 */

#ifndef SPRING_2018_PROGRAM_5_BINARY_SEARCH_TREE_GARYALLEN4_BINARYSEARCHTREE_H
#define SPRING_2018_PROGRAM_5_BINARY_SEARCH_TREE_GARYALLEN4_BINARYSEARCHTREE_H


class node {
    friend class BinarySearchTree;

private:
    int courseNumber;
    int counter;
    node *leftchild;
    node *rightchild;
};

class BinarySearchTree {
public:
    BinarySearchTree();
    bool empty(); // return true if the tree is empty, otherwise return false
    void Insert(int courseNum);//insert a value x
    bool IsThere(int courseNum);//return true if x is in the tree, otherwise return false
    void Delete(int courseNum); //if value x is in the tree, remove x
    void Display();// driver display method
    void DeleteAllOnes(); //driver method to delete all nodes with count equal to one

private:
    node *root;//pointer to the root node
    void DeleteAllOnes(node *p); //recursively iterate through tree and delete values
    void Display(node *p); //recursively display values in tree in order from least to greatest

};


#endif //SPRING_2018_PROGRAM_5_BINARY_SEARCH_TREE_GARYALLEN4_BINARYSEARCHTREE_H

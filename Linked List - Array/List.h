/*
 * Author: Gary Allen
 * Date: 02/09/2018
 * Assignment: Program #2: Linked List Array
 * File: List.h
 * Description: This is the header file containing all methods, variables, and arrays to be used throughout the program
 */

#include<string>

using namespace std;
typedef string ElementType;
const int MAX = 100;

class List {
public:
    List(); // Create an empty list
    bool isEmpty(); // Return true if the list is empty, otherwise return false
    void InsertAtEnd(ElementType x); // Insert a value x at the end of the list
    void ReverseDisplay(); // Display the values in the list in reverse (do not reverse the actual list)
    void GetValueAt(int n); // Return the value at the provided location n
    void DeleteAll(ElementType x); // If value x is in the list, remove all instances of x
    void
    Display(string type); // Display the strings in the list based on the user's specification (all of them, the even length ones, or the odd length ones).
    void Sort(); // Sort the list of strings based on length (shortest to longest)
    double Median(); // Compute and return the median string length for the strings in the list (must be sorted)
    void Shuffle(); // Shuffle the strings in the list around

private:
    int N; // Number of values in list
    ElementType listArray[MAX]; // The array to hold the list values
};

# Assignment #2: List - Array Implementation

*Review pages 6-7 in "From Java to C++" notes.* 

*Due **Friday, February 9th, 2017 @ 11:59PM EST***

## Directions
Create a `List` object. Using the following definition (`List.h` file is also in the repository for your convenience) for a list, implement the member functions (methods) for the List class and store the implementation in a file called `List.cpp`.  Use an array to implement the list. Write the client code (the main method and other non-class methods) and put those methods in file `main.cpp`. 

```
// file: List.h 
#include<string>
using namespace std;
typedef string ElementType;
const int MAX = 100;
class List
{
 public: 
   List(); // Create an empty list
   bool isEmpty(); // Return true if the list is empty, otherwise return false
   void InsertAtEnd(ElementType x); // Insert a value x at the end of the list
   void ReverseDisplay(); // Display the values in the list in reverse (do not reverse the actual list)
   void GetValueAt(int n); // Return the value at the provided location n
   void DeleteAll(ElementType x); // If value x is in the list, remove all instances of x
   void Display(String type); // Display the strings in the list based on the user's specification (all of them, the even length ones, or the odd length ones).
   void Sort(); // Sort the list of strings based on length (shortest to longest)
   double Median(); // Compute and return the median string length for the strings in the list (must be sorted)
   void Shuffle(); // Shuffle the strings in the list around

 private:
	int N; // Number of values in list
  ElementType listArray[MAX]; // The array to hold the list values
};
```

Write a program to create a single list. Your client code should be menu driven using the following menu options:

```
  1. Insert
  2. Reverse Display
  3. Show Value at Location
  4. Delete Value
  5. Display Values (All, Even, or Odd)
  6. Sort
  7. Median
  8. Shuffle
  9. Exit
```
**Option 1:** Prompt the user for a non-empty string to insert at the end of the list.

**Option 2:** Display all of the strings in the list in reversed order without actually reversing the list.

**Option 3:** Prompt the user for a location in the linked list and display the string at that location.

**Option 4:** Prompt the user for which string to remove from list. Remove every instance of the value specified.

**Option 5:** Prompt the user to dislay either all strings in the list, all strings of even length, or all strings of odd length.

**Option 6:** Sort the values in the list based on string length from shortest to longest.

**Option 7:** Find the median length of the strings in the list and display it.

**Option 8:** Shuffle the strings in the list around.

**Option 9:** Exit the program.

## Guidelines:

- Program should not crash when incorrect input is provided when they are prompted to select a command
- Menu should be displayed after completing each action for user to reference.
- Command 5 should only accept "All", "Even", or "Odd". Any other input should be denied.




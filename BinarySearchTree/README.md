# Student: 


## Grading: 

# Assignment #5: Binary Search Tree

*Due **Wednesday, April 4th , 2018 @ 11:59PM EST***

## Directions
The Computer Science Department would like to decide which courses to offer for the next semester and would like to 
offer only the courses that are in demand by the students.  Write a program to allow the students to input the courses 
that they would like to take the next semester. The first time a course is submitted by a student, the course comes 
into existence and a counter for the course is set to 1 (showing that one student is interested in taking the course). 
If the course already exists and a student would like for the course to be offered, the counter for the course is 
incremented. Display the course numbers (from smallest to largest) with corresponding counters. Remove the courses 
with only one student interested in taking the course. Display the course numbers (from smallest to largest) with 
corresponding counters after courses with one interested student have been deleted.


## Guidelines

-	Use a binary search tree to store the information on the courses. 
-	Use the appropriate binary tree traversal that will give you the correct output. 


There are several ways to deal with the fact that the node will store the **course number** as well as a **counter**


**The following definition for the binary search tree modifies the node class to hold the two values:**


```

// file binarySearchTree.h

class node
{
   friend class BinarySearchTree;
   private:
int courseNumber;
int counter;
   	node * leftchild;
   	node * rightchild;
};

class BinarySearchTree
{
 public: 
   BinarySearchTree();
   bool empty(); // return true if the tree is empty, otherwise return false
   bool Insert(int courseNum);//insert a value x 
   bool IsThere(int courseNum); 
//return true if x is in the tree, otherwise return false
   void Delete(int courseNum); //if value x is in the tree, remove x
   void Display();// Display the data values stored from smallest to largest
  
 private:
	node * root;//pointer to the roor node
};

```


**The following definition for the binary search tree using a struct to hold the two values:**



Write a program to create a single LinkedList. Your client code should be menu driven using the following menu options:

```
// file binarySearchTree.h

struct course{
	int courseNumber;
	int counter;
};

typedef course ElementType;
class node
{
   friend class BinarySearchTree;
   private:
ElementType data;
   	node * leftchild;
   	node * rightchild;
};

class BinarySearchTree
{
 public: 
   BinarySearchTree();
   bool empty(); // return true if the tree is empty, otherwise return false
   bool Insert(ElementType x);//insert a value x 
       bool IsThere (ElementType  x); 
//return true if x is in the tree, otherwise return false
   void Delete(ElementType x); //if value x is in the tree, remove x
   void Display();// Display the data values stored from smallest to largest
  
 private:
	node * root;//pointer to the roor node
};

```


### Example
```

User inserts the following course numbers:

285
280
163
165
476
365
163
280
280
165
365
365
165
280
476
163
163
385


Program output:

List of all courses:
163 – 4
165 – 3
280 – 4
285 – 1
365 – 3
385 – 1
476 – 2

List of courses more than one student interested:
163 – 4
165 – 3
280 – 4
365 – 3
476 – 2

```


## Guidelines:

- You must submit three files: `main.cpp`, `binarySearchTree.h`, & `binarySearchTree.cpp`
- Your BST should only have the functions listed above.
- Your main should prompt the user to input as many course numbers as they'd like and then display all the courses, 
followed by all the courses with more than one student interested.
- To display all the courses that have more than one student interested, you should delete all the nodes with counter less than 2.
- Program should not crash when incorrect input is provided when the user is prompted to insert course numbers.
- Program should allow user to start over after displaying the courses. (Feel free to implement a full menu of options).

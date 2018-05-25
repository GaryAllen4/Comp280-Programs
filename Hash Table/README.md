# Student: 


## Grading: 

# Assignment #6: Hash Table

*Due **Sunday, April 22nd , 2018 @ 11:59PM EST***

Write a program to implement a hash table. You may use linear probing, quadratic probing 
or the chaining method to resolve collisions. Use the following hash function h(x) = x 
mod (size of the table). Choose the appropriate class definition for the hash table based 
on the collision resolving method that you select. 


### Use the following class definition for the chaining method:

**Note:  Use your linked list code to implement the hash table.**

```
#include “Linkedlist.h”

class hashtable {

  public:
	hashtable (int size);//Allocate space for the hash tables based on the
	//parameter size.  Set the size and the count.
	void Insert(int value);	//insert the value in the hash table
	void display(); 	//Display the content of the hash table1.
	  
  private:
	LinkedList * table;	//hash table is an array of linkedlists
	int count;	//number of values stored in the hash table
	int size; //size of the hash table
};
```
### Use the following class definition for Linear Probing or Quadratic Probing:

**Note: When using quadratic probing, if the calculated location value is out of the 
range of the table, mod the value with by the table size and if the calculated location 
is negative, the add table size to the value.**

```
class hashtable {

  public:
	hashtable (int size);//Allocate space for the hash tables based on the
	//parameter size.  Set the size and the count.
	void Insert(int value);	//insert the value in the hash table
	void display(); 	//Display the content of the hash table1.
	bool Isfull();	//return true if the hast table is full, otherwise return false
  
  private:
	int * table; // hash table 
    int count;	//number of values stored in the hash table
	int size; //size of the hash table
};
```
First ask the user for the table size and let your program be menu driven using the following menu options:
```
Option 1 – Insert a value into the hash tables
Option 2 – Display the hash table
Option 3 – Exit Program
```

Sample output for the display method using the following:

Table size is 10.  Values are stored in the following order: 285, 280, 365, 476, 385, 165, 285, 165, 163, 180, 280, 165

Output from display method using chaining:
```
0 – 180-1, 280-2
1 – 
2 – 
3 – 163-1
4 – 
5 – 165-3, 285-2, 365-1, 385-1 
6 – 476-1
7 – 
8 – 
9 – 
```
Output from display method using linear probing:
```
0 – 280-2
1 – 180-1
2 – 
3 – 163-1
4 – 
5 – 285-2
6 – 365-1
7 – 476-1
8 – 385-1
9 – 165-3

```
Output from display method using quadratic probing:
````
0 – 280-2
1 – 180-1
2 – 
3 – 163-1
4 – 385-1
5 – 285-2
6 – 365-1
7 – 476-1
8 – 
9 – 165-3

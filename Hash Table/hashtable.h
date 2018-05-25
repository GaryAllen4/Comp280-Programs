/*
 * Author: Gary Allen
 * Date: 04/22/2018
 * Assignment: Program #6 - Hash Table
 * File: hashtable.h
 * Description: This file has all the necessary methods and variables for the hashtable class
 */// Created by Gary on 4/11/2018.
//

#ifndef SPRING_2018_PROGRAM_6_HASH_TABLE_GARYALLEN4_HASHTABLE_H
#define SPRING_2018_PROGRAM_6_HASH_TABLE_GARYALLEN4_HASHTABLE_H

class hashtable {
public:
    hashtable(int size);//Allocate space for the hash tables based on the
    //parameter size.  Set the size and the count.
    void Insert(int value);    //insert the value in the hash table
    void display();    //Display the content of the hash table1.
    bool Isfull();    //return true if the hast table is full, otherwise return false

private:
    int *table; // hash table
    int count;    //number of values stored in the hash table
    int size; //size of the hash table

};


#endif //SPRING_2018_PROGRAM_6_HASH_TABLE_GARYALLEN4_HASHTABLE_H

/*
 * Author: Gary Allen
 * Date: 03/18/2018
 * Assignment: Program #4 - Stacks & Queues
 * File: Card.h
 * Description: All methods and variables that are used to create and store a Card
 */

#ifndef SPRING_2018_PROGRAM_4_STACKS_QUEUES_GARYALLEN4_CARD_H
#define SPRING_2018_PROGRAM_4_STACKS_QUEUES_GARYALLEN4_CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card {
public:
    Card(); //create card properties
    string toString(); //convert card to string to be displayed
    Card(int suit, int cardNum); //initialize new card
    string checkFace(); //check the face of an individual card for comparison
    int face, suit; //card face and suit values for each card


};


#endif //SPRING_2018_PROGRAM_4_STACKS_QUEUES_GARYALLEN4_CARD_H

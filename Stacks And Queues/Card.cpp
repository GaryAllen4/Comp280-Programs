/*
 * Author: Gary Allen
 * Date: 03/18/2018
 * Assignment: Program #4 - Stacks & Queues
 * File: Card.cpp
 * Description: This file implements(gives instructions) all the methods for the Card class
 */

#include "Card.h"

using namespace std;

//used to convert a card's objects to string for the user's knowledge
string Card::toString() {
    string nameSuit;
    string nameFace;
    if (suit == 1) {
        nameSuit = "Hearts";
    } else if (suit == 2) {
        nameSuit = "Diamonds";
    } else if (suit == 3) {
        nameSuit = "Spades";
    } else if (suit == 4) {
        nameSuit = "Clubs";
    }
    if (face == 1) {
        nameFace = "Ace";
    } else if (face == 10) {
        nameFace = "Jack";
    } else if (face == 11) {
        nameFace = "Queen";
    } else if (face == 12) {
        nameFace = "King";
    } else {
        string s = to_string(face);
        nameFace = s;
    }
    return nameFace + " of " + nameSuit;
}

//no arg constructor to set default values
Card::Card() {

}

//constructor with args to initialize a new card
Card::Card(int cardsuit, int cardNumb) {
    suit = cardsuit;
    face = cardNumb;
}

//used to compare the faces of two cards
string Card::checkFace() {
    string nameSuit;
    string nameFace;
    if (suit == 1) {
        nameSuit = "Hearts";
    } else if (suit == 2) {
        nameSuit = "Diamonds";
    } else if (suit == 3) {
        nameSuit = "Spades";
    } else if (suit == 4) {
        nameSuit = "Clubs";
    }
    return nameSuit;
}
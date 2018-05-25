/*
 * Author: Gary Allen
 * Date: 03/18/2018
 * Assignment: Program #4 - Stacks & Queues
 * File: main.cpp
 * Description: Executes the program using implemented methods and variables
 */
#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Card.h"
#include <ctime>

//used to display a player's hand
void Display(Queue player) {
    Queue temp;//set temp to empty and then add player objects to temp then put them back in player
    Card card; // create new card object
    while (player.Empty() == false) {
        player.Front(card);//retrieve card from front of player's hand
        player.RemoveQ(); //remove card from front
        temp.AddQ(card);//add that card to the temporary Q
    }
    Card tempCard;
    while (temp.Empty() == false) {
        temp.Front(tempCard);
        cout << tempCard.toString() << endl;//FIX this would before printing a card number such as 112
        temp.RemoveQ(); //removes card from temporary Q
        player.AddQ(tempCard); //put card back in player's hand
    }

}

//used to show the next card from the top of the dealer's stack
void showDealerCard(Card showCard) {
    cout << showCard.toString() << endl;
}

// check for a winner before going to the next player's turn
bool checkWinner(Queue player) {
    Queue tempQ; // Queue object to make a temporary Queue that holds cards from a player's hand
    Card card; //Card object to hold a retrieved from the player's hand
    Card compareCard; //used to compare with the other cards in a player's hand
    int compareCount = 0; //used to count the number of cards with the same face
    while (player.Empty() == false) {
        player.Front(card);//retrieve card from front of player's hand
        player.RemoveQ(); //remove card from front
        tempQ.AddQ(card);//add that card to the temporary Q
    }
    Card tempCard; //used to compare with another card
    tempQ.Front(compareCard);
    tempQ.RemoveQ();
    player.AddQ(compareCard);
    while (tempQ.Empty() == false) {
        tempQ.Front(tempCard);
        tempQ.RemoveQ();
        if (tempCard.checkFace() == compareCard.checkFace()) {
            compareCount++;
        }
        player.AddQ(tempCard);
    }

    if (compareCount == 4) {
        return true;
    } else
        return false;
}

int main() {
    bool gameisNotOver = true; //used to control if the game process is over
    const int constant = 52; //used to initialize the array size
    Stack dealerStack; //object to control the dealer's stack
    Queue players[4];//array of players that hold queues which are their hand of cards
    Stack discardStack; //used to control the stack of discarded cards
    Card cards[constant];// create an array of 52 card objects


    int i = 0;//increment index of the array of created cards
    for (int suit = 1; suit < 5; suit++) { //create cards
        for (int face = 1; face < 14; face++) {
            Card card(suit, face); //create a new card with a face and suit
            cards[i] = card; //place that card in the array of Cards
            i++;
        }
    }

    int s; //used to help create a temporary card object
    int f;//used to help create a temporary card object
    srand(time(0));
    for (int i = 51; i >= 0; i--) { //shuffle cards
        int j = rand() % (i + 1); //creates and stores a random number from 0 to 52
        //variable stores the value temporarily to be transferred to another position
        Card temp(s, f);
        temp = cards[j];
        cards[j] = cards[i];
        cards[i] = temp;
    }

    for (int i = 0; i < 52; i++) { //generate dealer's deck
        dealerStack.push(cards[i]);
    }

    Card cardNumber; //used to retrieve a card from the dealer and give it to the specified player

    for (int i = 0; i < 4; i++) { //deal 5 cards to each player's queue
        for (int j = 0; j < 5; j++) {
            dealerStack.top(cardNumber);
            dealerStack.pop();
            players[i].AddQ(cardNumber);
        }
    }

    bool gameInSession = true; //used to tell if the game is still in play
    int playerTurn; //used to keep track of the player rotations for turns
    Card cardOffered; //used to hold the card offered from the top of the dealer's stack
    int usersChoice; //used to hold the user's choice to continue play or not
    Card oldestCard; //retrieves the oldest card in a player's hand
    int answer; //used to hold the user's answer to continue playing or not
    cout << "WELCOME USER, THANKS FOR PLAYING THIS GAME. GOOD LUCK!" << endl;
    while (gameInSession) {
        playerTurn = 0;
        srand(time(0));
        for (int i = 0; i < 4; i++) {
            if (dealerStack.empty()) {
                gameInSession = false;
                string userAnswer;
                cout << "It's A DRAW! Play Again?! Yes or No?" << endl;
                cin >> userAnswer;
                if (userAnswer == "YES" || userAnswer == "Yes" || userAnswer == "yes") {
                    main();
                }
                break;
            } else if (playerTurn == 0) {
                dealerStack.top(cardOffered);
                cout << "Your current hand:" << endl;
                Display(players[i]);
                cout << "" << endl;
                dealerStack.pop();
                cout << "The dealer has offered you the following card below:" << endl;
                showDealerCard(cardOffered);//display card
                cout << "" << endl;
                cout << "Would you like to keep this card? Type 1 for yes or 0 for no" << endl;
                cin >> usersChoice;
                if (usersChoice == 1) { //works
                    players[i].Front(oldestCard);
                    players[i].RemoveQ();
                    players[i].AddQ(cardOffered);
                    discardStack.push(oldestCard);
                    if (checkWinner(players[i])) {//check for a winner
                        gameInSession = false;
                        cout << "WINNING HAND:" << endl;
                        cout << "" << endl;
                        Display(players[i]);
                        cout << "YOU WIN! GREAT GAME" << endl;
                        cout << "User, would you like to play another game? Type 1 for yes or 0 for no."
                             << endl;
                        cin >> answer;
                        if (answer == 1) {
                            gameInSession = false;
                            main();
                        } else if (answer == 0) {
                            cout << "THANKS FOR PLAYING!" << endl;
                            gameInSession = false;
                            break;
                        }
                        break;
                    }
                } else {
                    discardStack.push(cardOffered);
                }


            } else {
                dealerStack.top(cardOffered);
                cout << "Bot Number " << i << " hand is the following:" << endl;
                Display(players[i]);
                cout << "" << endl;
                dealerStack.pop();
                int random = rand() % 2; //random number from 0 to 1
                if (random == 1) {
                    players[i].Front(oldestCard);
                    players[i].RemoveQ();
                    players[i].AddQ(cardOffered);
                    discardStack.push(oldestCard);
                    if (checkWinner(players[i]) == true) {//check winner
                        gameInSession = false;
                        cout << "WINNING HAND:" << endl;
                        cout << "" << endl;
                        Display(players[i]);
                        cout << "Bot " << i << " has won!" << endl;
                        cout << "" << endl;
                        cout << "User, would you like to play another game? Type 1 for yes or 0 for no."
                             << endl;
                        cin >> answer;
                        if (answer == 1) {
                            gameInSession = false;
                            main();
                            break;
                        } else if (answer == 0) {
                            cout << "THANKS FOR PLAYING!" << endl;
                            gameInSession = false;
                            break;
                        }
                        break;
                    }
                } else {
                    discardStack.push(cardOffered);
                }


            }

            playerTurn++;
        }


    }


}
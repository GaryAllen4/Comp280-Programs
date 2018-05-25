# Assignment #4: Stacks and Queues


*Due **Sundaygh, March 16th, 2017 @ 11:59PM EST***

## Directions


Create  `Stack` & `Queue` objects using the  `Stack.h` & `Queue.h` definitions in this repository. 
Implement the member methods for the `Stack` & `Queue` classes and store their implementations in files called 
`Stack.cpp` & `Queue.cpp`.  Use their respective `node` and `qnode` structs to implement them.
**You may not use arrays to implement them**. Write the client code (the main method and other non-class methods you wish to implement) 
in a file called `main.cpp`. 

**YOU MAY NOT ADD EXTRA METHODS TO THE `Stack` & `Queue` CLASSES** (Points will be deducted if you do.)


Write a program for simulating a card game with the following rules:
- Each player is dealt 5 cards, and must maintain 5 cards in their hand at all times.
- The winner is the first player with 5 cards from the same suit.
- At a player's turn, he/she has two options:
1.	Accept a new card from the dealer (the dealer’s top card) and discard their oldest card (their front card) to the top of the discard pile.
2.	Decline the new card from the dealer and discard it to the top of the discard pile
- The game must have 4 players (one human and 3 bots)
- Players are identified as Human, Bot 1, Bot 2, and Bot 3.
- The game is started by a single card being dealt to the Human, Bot 1, Bot 2, Bot 3 and so on until each of the players has 5 cards.  
- After the first hand is dealt to each player, if there is a player with all 5 cards in the same suit, that player is the winner and the game is over.  If there is more than one player with all 5 cards of the same suit, the game is a draw. If there is not a winner or a draw, the game continues by the Human getting the first turn, then Bot 1, then Bot 2, then Bot 3, and so on.
- If the dealer runs out of cards before there is a winner they must pick up the discard stack of cards to replace their empty stack of cards.
- If the dealer runs out of cards and the discard stack is empty, the game ends in a draw.


In summary, on a player's turn, the player will:
1. Display current hand (I would suggest using a temporary queue to do this)
2. Get (*pop*) a new card (from the dealer) 
3. Discard (*push*) a card (the new card or the card that has been in the player's hand the longest) onto the discard pile
4. Check to see if he/she is a winner (display updated hand)


## Programming Guidelines:
- Use a stack to represent the pile of discarded cards and a second stack for the dealer’s cards.
- Use an array of queues to represent the hands of all players (index 0 is the human, 1 is bot 1 and so on). 
- The dealer's stack should be filled with the 52 cards of a regular playing deck (no jokers)
- Before game play begins, the cards should be randomly pushed onto the dealer's stack. You should randomly generate the suit and 
a number 1 through 13, where 1 is the Ace, 11 is the Jack, 12 is the Queen and 13 is King.  A suit is a number 1, 2, 3, or 4 
where 1 represents the heart, 2 the diamond, 3 the spade, and 4 the club. To keep things simple in the Stacks and Queue, 
you can represent a single card by combining the suit and number into a single 3-digit value (i.e. 112 = Queen of Hearts, 401 = Ace of Clubs)
- Your program should keep track of the cards that are randomly generated in order to avoid duplication of the same card 
in the dealer's deck. (Ex: you can have a boolean array in your main of size 52 with each value set to false, as numbers 
are generated, set their index in the array to true to let you know it is already in the dealer's stack.)
- Your program should prompt each user asking which card to discard, the new card from the dealer or the card that he/she 
has had the longest (this choice should be random for the bots, easy way to implement would be 1 for new card and 0 for old card).
- Your program should print out the name and hand of the winning player.  If there is no winner your program should print 
a message stating so.
- After a game is over, ask the human if he/she wishes to play another game.  If the user answers yes, start another game.  
If the user answers no, terminate the program.

## Sample Gameplay:

**-Dealer is dealing cards-**	

**Your turn:**
	
	
Current hand:

- 10 of Spades
- Ace of Diamonds
- 2 of Hearts
- King of Hearts
- 8 of Hearts


Dealer Card: 4 of Hearts	(popped from dealers hand)

Would you like to keep this new card? (yes/no)

Input: yes

**-10 of Spades removed from hand and pushed to discard stack, 4 of hearts added to hand-**

Updated Hand:

- Ace of Diamonds
- 2 of Hearts
- King of Hearts
- 8 of Hearts
- 4 of Hearts
	
Not five of a kind

…

// simulate for bots

…	

Your turn:
	
Current hand:

- Ace of Diamonds
- 2 of Hearts
- King of Hearts
- 8 of Hearts
- 4 of Hearts


Dealer Card: 
3 of Hearts	(popped from dealers hand)

Would you like to keep this new card? (yes/no)

Input: yes

**-Ace of Diamonds removed from hand and pushed to discard stack, 3 of hearts added to hand-**

Updated Hand:

- 3 of Hearts
- 2 of Hearts
- King of Hearts
- 8 of Hearts
- 4 of Hearts

**Five of a kind! You win!**

Play again (yes/no)?

No



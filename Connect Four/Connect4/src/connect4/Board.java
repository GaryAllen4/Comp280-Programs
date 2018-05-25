/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package connect4;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author Gary Allen 
 * Assignment: Program #1 - Connect Four 
 * File: Board.java
 * Description: This file creates, displays, and updates the game board. It also
 * makes the moves in the game, checks for a winner and re-runs if selected.
 */
public class Board {

    //constructor method to assign default values
    public Board() {

    }

    //function to display the game board
    public static void showBoard(String[][] board) {

        for (int row = 0; row < board.length; row++) {

            for (int column = 0; column < board[row].length; column++) {
                System.out.print(board[row][column]);
            }
            System.out.println();
        }

    }

    //function that makes the board for connect four
    public static String[][] makeBoard() {

//variable used to hold the game board creation
        String[][] board = new String[8][15];

        for (int row = 0; row < board.length; row++) {

            for (int column = 0; column < board[row].length; column++) {

                if (column % 2 == 0) {
                    board[row][column] = "|";
                } else {
                    board[row][column] = " ";
                }

                if (row == 6) 
                {
                    board[row][column] = "-";
                }

                if (row == 7) { 
                    board[7][1] = "1";
                    board[7][3] = "2";
                    board[7][5] = "3";
                    board[7][7] = "4";
                    board[7][9] = "5";
                    board[7][11] = "6";
                    board[7][13] = "7";
                }
            }

        }

        return board;

    }

    //function used to start the gameplay
    public static void startGame() {
        //variable to hold the construction of game board
        String[][] board = makeBoard(); 

        //variable used to show the game board while the game is still being played and vice versa
        boolean gameInPlay = true;

        showBoard(board); 
        // variable to hold a number for the first player
        int playerOne = 0; // variable to hold a number for the first player
        System.out.println("Select a color: Type the letter B for Black or R for Red.");
        Scanner read = new Scanner(System.in);
        String colorChoice = read.next();

        if (colorChoice.equalsIgnoreCase("R")) {

            playerOne = 0;

        } else if (colorChoice.equalsIgnoreCase("B")) {

            playerOne = 1;

        } else {
            System.out.println("Wrong Character, Please Try Again.");
            startGame();
        }
        while (gameInPlay) { //while the game is still in play 

            if (playerOne % 2 == 0) { //if playerOne 
                userRedPiece(board);
                computersBlackPiece(board);              
            } else {
                userBlackPiece(board);
                computersRedPiece(board);               
            }
            //variable used to keep up with the number of board spaces used
            int spaceCounter = 0;

            for (int row = 0; row < 6; row++) {

                for (int col = 1; col < 14; col += 2) {
                    if (board[row][col] == "B" || board[row][col] == "R") {
                        spaceCounter++;
                    }
                }

            }
            if (spaceCounter == 42) {
                System.out.println("It's A Tie! I Guess That's Better Than A Loss LOL");
                restart();
                break;
            }

            showBoard(board);

            //We need to keep track of the turn
            if (checkForAWinner(board) == "R") {
                System.out.println("WINNER! THE RED PLAYER WON!");
                gameInPlay = false;
            }

            if (checkForAWinner(board) == "B") {
                System.out.println("WINNER! THE BLACK PLAYER WON!");
                gameInPlay = false;
            }

        }
        restart();
    }

    //function to allow the user to restart the game when it has ended
    public static void restart() {
        System.out.println("Would you like to play a new game? Type Y for Yes or N for No");

        //reads data enteredby the user
        Scanner read = new Scanner(System.in);
        //variable used to compare to decide if user wants to play agaim
        String colorChoice = read.next();

        if (colorChoice.equalsIgnoreCase("Y")) {
            startGame();

        } else if (colorChoice.equalsIgnoreCase("N")) {
            System.out.println("THANKS FOR PLAYING! TO PLAY AGAIN RE-RUN THE PROGRAM.");
        } else {
            System.out.println("INCORECT CHARACTER! PLEASE SELECT AGAIN.");
            restart();
        }
    }

    //allows the user, who is black, to make a move on the game board
    public static void userBlackPiece(String[][] board) {
        System.out.println("Drop your black game piece at which column ? ");

        //used to read data entered by the user
        Scanner read = new Scanner(System.in);

        //equation to convert user input to the correct column they want to use
        int column = 2 * read.nextInt() - 1;

        for (int row = 6; row >= 0; row--) {

            if (board[row][column] == " ") {

                board[row][column] = "B";

                break;

            }

            if (board[0][column] == "B" || board[0][column] == "R") {
                System.out.println("THIS COLUMN IS FULL! PICK ANOTHER ONE.");
                userBlackPiece(board);
                break;
            }

        }

    }

    //to give instructions for the bots turn to make a move, whihc is the "color" black
    public static void computersBlackPiece(String[][] board) {

        //used to generate a random number and use it to pick a column to drop a game piece
        Random botMove = new Random();

        //equation to convert user input to the correct column they want to use
        int column = 2 * botMove.nextInt(6) + 1;

        for (int row = 6; row >= 0; row--) { //to check to see if their are filled spaces in the column and if so then drop the piece in the row above

            if (board[row][column] == " ") {

                board[row][column] = "B";

                break;

            }

            if (board[0][column] == "R" || board[0][column] == "B") {
                computersBlackPiece(board);
                break;
            }

        }

    }

    //allows the user to make a move in any available space on the game board
    public static void userRedPiece(String[][] board) {

        System.out.println("Drop your red game piece at which column? ");

        //used to read data entered by the user
        Scanner read = new Scanner(System.in);

//equation to convert user input to the correct column they want to use
        int column = 2 * read.nextInt() - 1;

        for (int row = 6; row >= 0; row--) { //to check to see if their are filled spaces in the column and if so then drop the piece in the row above

            if (board[row][column] == " ") {

                board[row][column] = "R";

                break;

            }
            if (board[0][column] == "R" || board[0][column] == "B") {
                System.out.println("THIS COLUMN IS FULL! PICK ANOTHER ONE.");
                userRedPiece(board);
                break;
            }

        }

    }

    //to give instructions for the bots turn to make a move, whihc is the "color" red
    public static void computersRedPiece(String[][] board) {
        //used to generate a random number and use it to pick a column to drop a game piece
        Random botMove = new Random();

        //equation to convert user input to the correct column they want to use
        int column = 2 * botMove.nextInt(6) + 1;

        for (int row = 6; row >= 0; row--) { //to check to see if their are filled spaces in the column and if so then drop the piece in the row above

            if (board[row][column] == " ") {

                board[row][column] = "R";

                break;

            }
            if (board[0][column] == "R" || board[0][column] == "B") {
                computersRedPiece(board);
                break;
            }

        }

    }

//to determine if user or bot has a winning pattern
    public static String checkForAWinner(String[][] board) {

        for (int row = 0; row < 6; row++) { //checks for horizontal line of four in a row

            for (int column = 0; column < 7; column += 2) {

                if ((board[row][column + 1] != " ")
                        && (board[row][column + 3] != " ")
                        && (board[row][column + 5] != " ")
                        && (board[row][column + 7] != " ")
                        && ((board[row][column + 1] == board[row][column + 3])
                        && (board[row][column + 3] == board[row][column + 5])
                        && (board[row][column + 5] == board[row][column + 7]))) {

                    return board[row][column + 1]; //return color of winning pattern
                }
            }

        }

        for (int row = 1; row < 15; row += 2) { //checking for vertical line winning pattern

            for (int column = 0; column < 3; column++) {

                if ((board[column][row] != " ")
                        && (board[column + 1][row] != " ")
                        && (board[column + 2][row] != " ")
                        && (board[column + 3][row] != " ")
                        && ((board[column][row] == board[column + 1][row])
                        && (board[column + 1][row] == board[column + 2][row])
                        && (board[column + 2][row] == board[column + 3][row]))) {

                    return board[column][row]; // returns  the color of winning pattern
                }
            }

        }

        for (int row = 0; row < 3; row++) {// checks for front and back diagonal winning patterns

            for (int column = 1; column < 9; column += 2) {

                if ((board[row][column] != " ")
                        && (board[row + 1][column + 2] != " ")
                        && (board[row + 2][column + 4] != " ")
                        && (board[row + 3][column + 6] != " ")
                        && ((board[row][column] == board[row + 1][column + 2])
                        && (board[row + 1][column + 2] == board[row + 2][column + 4])
                        && (board[row + 2][column + 4] == board[row + 3][column + 6]))) {

                   return board[row][column]; //returns the color of the winning pattern
                }

            }

        }

        for (int row = 0; row < 3; row++) {

            for (int column = 7; column < 15; column += 2) {

                if ((board[row][column] != " ")
                        && (board[row + 1][column - 2] != " ")
                        && (board[row + 2][column - 4] != " ")
                        && (board[row + 3][column - 6] != " ")
                        && ((board[row][column] == board[row + 1][column - 2])
                        && (board[row + 1][column - 2] == board[row + 2][column - 4])
                        && (board[row + 2][column - 4] == board[row + 3][column - 6]))) {

                    //returns the color of winning pattern
                    return board[row][column]; 
                }

            }

        }
//neither color has won yet
        return null; 

    }

}

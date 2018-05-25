/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package connect4;

/**
 *
 * @author Gary Allen
 * Assignment: Program #1 - Connect Four
 * File: Connect4.java
 * Description: This file starts the game.
 */
public class Connect4 {

    public static void main(String[] args) {
        System.out.println("Connect Four Game! Let the Games Begin.");
        
        //Board object to allow the usage of methods inside the board class
        Board game = new Board();
        game.startGame();

    }
}

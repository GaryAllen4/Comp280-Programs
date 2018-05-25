/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package connectfour;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;

/**
 *
 * @author G-Smoove
 */
public class GameBoard extends BorderPane{
    
    GameArea playGame;
    private Button colOne = new Button("0");
    private Button colTwo = new Button("1");
    private Button colThree = new Button("2");
    private Button colFour = new Button("3");
    private Button colFive = new Button("4");
    private Button colSix = new Button("5");
    private Button colSeven = new Button("6");
    private Button colEight = new Button("7");
    ButtonHandler buttonaction;
    
    public GameBoard() {
        playGame = new GameArea();
        buttonaction = new ButtonHandler();
         HBox hbox = new HBox(colOne, colTwo, colThree, colFour, colFive, colSix, colSeven, colEight); //controls put into HBox
        hbox.setAlignment(Pos.CENTER); //Centers the elements of HBox
        hbox.setSpacing(2);
        setBottom(hbox);
        setCenter(playGame);
        
        colOne.setOnAction(buttonaction);
         colTwo.setOnAction(buttonaction);
         colThree.setOnAction(buttonaction);
         colFour.setOnAction(buttonaction);
         colFive.setOnAction(buttonaction);
         colSix.setOnAction(buttonaction);
         colSeven.setOnAction(buttonaction);
         colEight.setOnAction(buttonaction);
        
    }
    
        private class ButtonHandler implements EventHandler<ActionEvent> {
        
        @Override
        public void handle(ActionEvent event) {
           
        }

    }

}

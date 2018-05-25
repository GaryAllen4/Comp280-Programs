/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package connectfour;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.scene.text.Font;
import javafx.stage.Stage;

/**
 *
 * @author G-Smoove
 */
public class GameStartPane extends GridPane{
    private Label instructions = new Label("");
    private Button black = new Button("Black");
    private Button red = new Button("Red");
    
    public GameStartPane() {
        instructions.setText("Select a color for your player");
        instructions.setFont(new Font("Times New Roman", 25));
        addRow(0, instructions);
        addRow(2, black, red);
        
        black.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                
                startGame();
            }
            
            
        });
        
        red.setOnAction(new EventHandler<ActionEvent>(){
            @Override
            public void handle(ActionEvent event) {
                
                startGame();
                
            }
            
        });
    }
    
    public void startGame() {
        this.setVisible(false);
        GameBoard gameBoard = new GameBoard();
        Scene gameScene = new Scene(gameBoard);
        Stage gameStage = new Stage();
        gameStage.setScene(gameScene);
        gameStage.setTitle("CONNECT FOUR!");
        gameStage.show();
        
    }
}

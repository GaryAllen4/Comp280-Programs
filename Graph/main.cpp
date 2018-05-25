/*
 * Author: Gary Allen
 * Date: 05/7/2018
 * Assignment: Program #7 - Graphs
 * File: main.cpp
 * Description: This file executes the program using implemented methods and variables
 */
#include <iostream>
#include "Graph.h"
#include <algorithm>

using namespace std;

int main() {
    cout << " American Southeast Airline Company (ASEA) Flight Destinations: " << endl;
    cout << "1. Nashville" << endl;
    cout << "2. DC" << endl;
    cout << "3. Greensboro" << endl;
    cout << "4. Dallas" << endl;
    cout << "5. Atlanta" << endl;
    cout << "6. Raleigh" << endl;
    cout << endl;


    cout << "How many of the cities above would you like to use? Type a number from 3 to 6." << endl;
    int verticesNum;
    cin >> verticesNum;
    Graph graphV(verticesNum);

    cout<<"How many direct flights(edges) would you like to use?"<<endl;
    int directFlights;
    cin>>directFlights;

    if(verticesNum*(verticesNum - 1) /2 < directFlights) {
        cout<<"You are trying to use too many edges. The maximum edges for "<<verticesNum<<" cities is "<<verticesNum*(verticesNum - 1) /2<<endl;
        cout<<"Try Again."<<endl;
        cout<<endl;
        main();

    } else {
        //counts the number of edges added
        int count = 0;

        cout<<"Now enter the "<< directFlights<< " flights(edges) you wish to use."<<endl;

        while (count != directFlights) {
            int city1, city2;
            string input1, input2;

            cin>> input1 >> input2;
            transform(input1.begin(), input1.end(), input1.begin(), ::toupper);
            transform(input2.begin(), input2.end(), input2.begin(), ::toupper);

            //compares user input to cities in the graph to give the specific index
            if (input1 == "NASHVILLE") {
                city1 = 0;
            } else if (input1 == "DC") {
                city1 = 1;
            } else if (input1 == "GREENSBORO") {
                city1 = 2;
            } else if (input1 == "DALLAS") {
                city1 = 3;
            } else if (input1 == "ATLANTA") {
                city1 = 4;
            } else if (input1 == "RALEIGH") {
                city1 = 5;
            } else {
                city1 = -1;
            }

//compares user input to cities in the graph to give the specific index
            if (input2 == "NASHVILLE") {
                city2 = 0;
            } else if (input2 == "DC") {
                city2 = 1;
            } else if (input2 == "GREENSBORO") {
                city2 = 2;
            } else if (input2 == "DALLAS") {
                city2 = 3;
            } else if (input2 == "ATLANTA") {
                city2 = 4;
            } else if (input2 == "RALEIGH") {
                city2 = 5;
            } else {
                city2 = -1;
            }

            //if the input is not a valid city
            if (city1 < 0 | city2 < 0) {
                cout << "Wrong Input. Try Again." << endl;
            } else {
                graphV.AddEdge(city1, city2);
                count++;
            }

        }
    }
//controls the runtime of the while loop
    bool running = true;
    while (running) {
        cout << "GRAPH MENU" << endl;
        cout << "1. Determine if there is a direct fight between two cities." << endl;
        cout << "2. Given a city, list all cities with direct flights from that city." << endl;
        cout << "3. Add a direct flight between two cities." << endl;
        cout << "4. Remove a direct flight between cities." << endl;
        cout << "5.  Print out cites using depth first search." << endl;
        cout << "6.  Print out cites using breadth first search." << endl;
        cout << "7.  Print out the adjacency matrix (one row per line of output)" << endl;
        cout << "8.  Check for connectivity **(10 extra  points)**" << endl;
        cout << "9.  Check for completeness **(10 extra points)**" << endl;
        cout << "10. End Program" << endl;
        cout << "" << endl;
        cout << "Select an Option Number." << endl;

        //intakes the user's choice from the menu
        int userInput;
        cin >> userInput;
        if (userInput == 1) {
            //used to intake the user's two city choices
            string input1, input2;
            //used to hold the integer representation for the given cities
            int city1, city2;

            cout << "Between which two cities would you like to check for a direct flight?" << endl;
            cin >> input1 >> input2;
            transform(input1.begin(), input1.end(), input1.begin(), ::toupper);
            transform(input2.begin(), input2.end(), input2.begin(), ::toupper);

            //compares user input to cities in the graph to give the specific index
            if (input1 == "NASHVILLE") {
                city1 = 0;
            } else if (input1 == "DC") {
                city1 = 1;
            } else if (input1 == "GREENSBORO") {
                city1 = 2;
            } else if (input1 == "DALLAS") {
                city1 = 3;
            } else if (input1 == "ATLANTA") {
                city1 = 4;
            } else if (input1 == "RALEIGH") {
                city1 = 5;
            } else {
                city1 = -1;
            }

//compares user input to cities in the graph to give the specific index
            if (input2 == "NASHVILLE") {
                city2 = 0;
            } else if (input2 == "DC") {
                city2 = 1;
            } else if (input2 == "GREENSBORO") {
                city2 = 2;
            } else if (input2 == "DALLAS") {
                city2 = 3;
            } else if (input2 == "ATLANTA") {
                city2 = 4;
            } else if (input2 == "RALEIGH") {
                city2 = 5;
            } else {
                city2 = -1;
            }

            if (city1 < 0 | city2 < 0) {
                cout << "Wrong Input. Try Again." << endl;//tell user they put wrong input
            } else {
                if (graphV.isFlight(city1, city2)) {
                    cout << "Yes, there is a direct flight between city the two cities " << endl;
                } else {
                    cout << "There is not a direct flight between these two cities" << endl;
                }
            }

        } else if (userInput == 2) {
            //used to hold the user's string input for of a city
            string input1;
            //city converted to its integer representation
            int city;
            cout << "Which city would you like to see all direct flights from?" << endl;
            cin >> input1;
            transform(input1.begin(), input1.end(), input1.begin(), ::toupper);

            //compares user input to cities in the graph to give the specific index
            if (input1 == "NASHVILLE") {
                city = 0;
            } else if (input1 == "DC") {
                city = 1;
            } else if (input1 == "GREENSBORO") {
                city = 2;
            } else if (input1 == "DALLAS") {
                city = 3;
            } else if (input1 == "ATLANTA") {
                city = 4;
            } else if (input1 == "RALEIGH") {
                city = 5;
            } else {
                city = -1;
            }

            if (city < 0) {
                cout << "Wrong input. Try again." << endl;
            } else {
                graphV.printAdjacent(city);
            }

        } else if (userInput == 3) {
            if (graphV.isComplete()) {

            } else {
                //used to intake the user's two city choices
                string input1, input2;
                //used to hold the integer representation for the given cities
                int city1, city2;

                cout << "Between which two cities would you like to add a direct flight?" << endl;
                cin >> input1 >> input2;

                transform(input1.begin(), input1.end(), input1.begin(), ::toupper);
                transform(input2.begin(), input2.end(), input2.begin(), ::toupper);
                //compares user input to cities in the graph to give the specific index
                if (input1 == "NASHVILLE") {
                    city1 = 0;
                } else if (input1 == "DC") {
                    city1 = 1;
                } else if (input1 == "GREENSBORO") {
                    city1 = 2;
                } else if (input1 == "DALLAS") {
                    city1 = 3;
                } else if (input1 == "ATLANTA") {
                    city1 = 4;
                } else if (input1 == "RALEIGH") {
                    city1 = 5;
                } else {
                    city1 = -1;
                }
                //compares user input to cities in the graph to give the specific index
                if (input2 == "NASHVILLE") {
                    city2 = 0;
                } else if (input2 == "DC") {
                    city2 = 1;
                } else if (input2 == "GREENSBORO") {
                    city2 = 2;
                } else if (input2 == "DALLAS") {
                    city2 = 3;
                } else if (input2 == "ATLANTA") {
                    city2 = 4;
                } else if (input2 == "RALEIGH") {
                    city2 = 5;
                } else {
                    city2 = -1;
                }

                if (city1 < 0 | city2 < 0) {
                    cout << "Wrong input. Try again." << endl;
                } else {
                    graphV.AddEdge(city1, city2);
                }
            }
        } else if (userInput == 4) {
            //used to intake the user's two city choices
            string input1, input2;
            //used to hold the integer representation for the given cities
            int city1, city2;

            cout << "Between which two cities would you like to delete a direct flight?" << endl;
            cin >> input1 >> input2;

            transform(input1.begin(), input1.end(), input1.begin(), ::toupper);
            transform(input2.begin(), input2.end(), input2.begin(), ::toupper);

            //compares user input to cities in the graph to give the specific index
            if (input1 == "NASHVILLE") {
                city1 = 0;
            } else if (input1 == "DC") {
                city1 = 1;
            } else if (input1 == "GREENSBORO") {
                city1 = 2;
            } else if (input1 == "DALLAS") {
                city1 = 3;
            } else if (input1 == "ATLANTA") {
                city1 = 4;
            } else if (input1 == "RALEIGH") {
                city1 = 5;
            } else {
                city1 = -1;
            }

            //compares user input to cities in the graph to give the specific index
            if (input2 == "NASHVILLE") {
                city2 = 0;
            } else if (input2 == "DC") {
                city2 = 1;
            } else if (input2 == "GREENSBORO") {
                city2 = 2;
            } else if (input2 == "DALLAS") {
                city2 = 3;
            } else if (input2 == "ATLANTA") {
                city2 = 4;
            } else if (input2 == "RALEIGH") {
                city2 = 5;
            } else {
                city2 = -1;
            }

            if (city1 < 0 | city2 < 0) {
                cout << "Wrong Input. Try Again." << endl;//tell user they put wrong input for first
            } else {
                graphV.DeleteEdge(city1, city2);
            }

        } else if (userInput == 5) {
            graphV.dfs();

        } else if (userInput == 6) {
            graphV.bfs();

        } else if (userInput == 7) {
            graphV.printMatrix();
        } else if (userInput == 8) {
            graphV.isConnected();

        } else if (userInput == 9) {
            graphV.isComplete();

        } else if (userInput == 10) {
            running = false;

        } else {
            cout << "Wrong Input. Select an Option from Above." << endl;
        }
    }
}
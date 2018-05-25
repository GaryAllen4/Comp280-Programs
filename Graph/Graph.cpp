/*
 * Author: Gary Allen
 * Date: 05/7/2018
 * Assignment: Program #7 - Graphs
 * File: Graph.cpp
 * Description: This file implements(gives instructions) all the methods for the Graph class
 */
#include <iostream>
#include "Graph.h"
#include <queue>
#include <stack>

using namespace std;

Graph::Graph(int v) {
    n = v;
    for (int i = 0; i < n; i++) { //initializes flight matrix to all 0's
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
}

bool Graph::isFlight(int v, int w) {
    if (matrix[v][w] == 1) {
        return true;
    }
    return false;
}

void Graph::AddEdge(int v, int w) {
    if (matrix[v][w] == 1 & matrix[v][w] == 1) {
        cout << "This edge is already in existence. Try another edge." << endl;
    } else {
        matrix[v][w] = 1;
        matrix[w][v] = 1;
    }
}

void Graph::DeleteEdge(int v, int w) {
    if (matrix[v][w] == 0 & matrix[v][w] == 0) {
        cout << "This edge already does not exist. Try another edge to delete." << endl;
    } else {
        matrix[v][w] = 0;
        matrix[w][v] = 0;
    }
}

void Graph::printAdjacent(int v) {
    string city;
    if (v == 0) {
        city = "NASHVILLE";
    } else if (v == 1) {
        city = "DC";
    } else if (v == 2) {
        city = "GREENSBORO";
    } else if (v == 3) {
        city = "DALLAS";
    } else if (v == 4) {
        city = "ATLANTA";
    } else if (v == 5) {
        city = "RALEIGH";
    }

    cout << " Flights from " << city << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (matrix[v][i] == 1) {
            if (i == 0) {
                cout << "NASHVILLE";
                cout << endl;
            } else if (i == 1) {
                cout << "DC";
                cout << endl;
            } else if (i == 2) {
                cout << "GREENSBORO";
                cout << endl;
            } else if (i == 3) {
                cout << "DALLAS";
                cout << endl;
            } else if (i == 4) {
                cout << "ATLANTA";
                cout << endl;
            } else if (i == 5) {
                cout << "RALEIGH";
                cout << endl;
            }
        } else {

        }
    }
    cout << endl;
}

void Graph::printMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
            if (j == n - 1) {
                cout << endl;
            }
        }
    }
}

void Graph::bfs() {
    //variable used to refer to a specified row of flights
    int vertex = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    visited[vertex] = true;
    cout << "NASHVILLE ";
    //queue object used to place, get, and remove flights
    queue<int> q;
    q.push(vertex);
    while (!q.empty()) {
        vertex = q.front();
        q.pop();
        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (matrix[vertex][neighbor] == 1) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;

                    if (neighbor == 1) {
                        cout << "DC ";
                    } else if (neighbor == 2) {
                        cout << "GREENSBORO ";
                    } else if (neighbor == 3) {
                        cout << "DALLAS ";
                    } else if (neighbor == 4) {
                        cout << "ATLANTA ";
                    } else if (neighbor == 5) {
                        cout << "RALEIGH ";
                    }
                }
            }
        }
    }
    cout << endl;
}

void Graph::dfs() {
    //source node
    int vertex = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    stack<int> s;
    s.push(vertex);
    while (!s.empty()) {
        vertex = s.top();
        s.pop();
        if (!visited[vertex]) {
            if (vertex == 0) {
                cout << "NASHVILLE ";
            } else if (vertex == 1) {
                cout << "DC ";
            } else if (vertex == 2) {
                cout << "GREENSBORO ";
            } else if (vertex == 3) {
                cout << "DALLAS ";
            } else if (vertex == 4) {
                cout << "ATLANTA ";
            } else if (vertex == 5) {
                cout << "RALEIGH ";
            }
            visited[vertex] = true;
        }

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (matrix[vertex][neighbor] == 1) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

bool Graph::isComplete() {
    //variable used to hold the number of edges for a complete undirected graph
    int complete = (n * (n - 1)) / 2;
    //used to control the edge to begin comparison with so edges are not repeated in the countEdges
    int count = 0;
    int countEdges = 0;
    for (int i = 0; i < n; i++) {
        for (int j = count; j < n; j++) {
            if (matrix[i][j] == 1) {
                countEdges++;
            }
        }
        count++;
    }
    if (complete == countEdges) {
        cout << "THE GRAPH IS NOW FULL." << endl;
        cout << endl;
        return true;
    }
    return false;
}

bool Graph::isConnected() {
//used to hold a current vertex/flight destination being evaluated
    int vertex = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    visited[vertex] = true;
    queue<int> q;
    q.push(vertex);
    while (!q.empty()) {
        vertex = q.front();
        q.pop();
        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (matrix[vertex][neighbor] == 1) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "The graph is disconnected" << endl;
            return false;
        }
    }
    cout << "The graph is connected" << endl;
    return true;
}
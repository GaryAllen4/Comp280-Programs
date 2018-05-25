/*
 * Author: Gary Allen
 * Date: 05/7/2018
 * Assignment: Program #7 - Graphs
 * File: Graph.h
 * Description: This file has all the necessary methods and variables for the Graph class
 */
#ifndef SPRING_2018_PROGRAM_7_GRAPHS_GARYALLEN4_GRAPH_H
#define SPRING_2018_PROGRAM_7_GRAPHS_GARYALLEN4_GRAPH_H


const int nmax = 100;
class Graph
{
public:
    Graph(int v);
    // initializes the number of vertices to v, and fills matrix with zeros 
    void AddEdge(int v, int w);
    //add an edge between v and w
    void DeleteEdge(int v, int w);
    //delete the edge between v and w
    void dfs();
    //print out the vertices using the depth first search.
    void bfs();
    //print out the vertices using the breadth first search

    void printMatrix();
    // print the content of the adjacency matrix with one row per line of output.
    void printAdjacent(int v);
    //print the vertices that are neighbors of the given vertex
    bool isConnected();
    //return true if the graph is connected
    //extra credit (10 points)
    bool isComplete();
    //return true if the graph is complete
    //extra credit(10 points)
    bool isFlight(int v, int w);
    //return true if there is a flight between v and w

    //extra credit to implement cities as strings instead of integers(10 points)
    //130 total possible points
    //other member functions, if needed

private:
    //other private member functions, if needed
    int n; // no. of vertices
    int matrix[nmax][nmax]; //2D array implementation for the graph
    bool visited[nmax]; //set each index value to true when visited
};



#endif //SPRING_2018_PROGRAM_7_GRAPHS_GARYALLEN4_GRAPH_H

# Program 7: Graphs


### Student: 

## Grading:
     
### Grade: 

*Due **Monday, May 6th, 2018 @ 11:59PM EST***

## Directions
Consider a program for American Southeast Airline Company (ASEA). The diagram below shows the cities 
that are serviced by ASEA.  The vertices show cities and the edges show the direct flights between the cities.


![alt text](https://github.com/comp280/Spring-2018-Program-7-Graphs/blob/master/sample-graph.png)


Let your program be menu driven using the following menu:

1.	Determine if there is a direct fight between two cities.

2.	Given a city, list all cities with direct flights from that city.

3.	Add a direct flight between two cities

4.	Remove a direct flight between cities

5.  Print out cites using depth first search.

6.  Print out cites using breadth first search.

7.  Print out the adjacency matrix (one row per line of output)

8.  Check for connectivity **(10 extra  points)**

9.  Check for completeness **(10 extra points)**

10.	End Program

## Programming Guidelines:

Implement the fight pattern for ASEA by using a graph. Use an adjacency matrix. 
The vertices will be represented by the indices of the two-dimensional array. 
Let 0 represent Nashville, 1 represent DC, 2 represent Greensboro, 3 represent Dallas, 
4 represent Atlanta and 5 represent Raleigh.


To begin the program, prompt the user to enter the number of cities (vertices) they would like to implement 
(at least 3 but no more than the 6 mentioned above) This number should be used to initialize the 2-D array. 
Then allow them to enter the number of direct flights (edges)
followed by each of the direct flights (pairs of edges, one on each new line). 

*sample user input for the graph displayed in the image above:*


This input describes the number of vertices, the number of edges and a list of edges.
```
6
7
0 3
0 4
1 5
2 5
2 4
3 4
4 5 
```

Guidelines for menu options:

Option 1.	Determine if there is a direct fight between two cities.
Prompt the user for the two cities and print at message 
stating whether or not there is a direct flight (edge) between the two cities.

Option 2.	Given a city, list all cities with direct flights from that city.
Prompt the user for a city and print all cities with direct flights from that city.

Option 3.	Add a direct flight between two cities
Prompt the user for the two cities that you want to add a direct flight between.

Option 4.	Remove a direct flight between cities
Prompt the user for the two cities that you want to remove a direct flight between.

Option 5.	Print out all the cities using Depth First Search (starting at Nashville)

Option 6.	Print out all the cities using Breadth First Search (starting at Nashville)

Option 7.   Print out the adjacency matrix (2-d array)

Option 8.	Check to see if the ASEA currently resembles a connected graph **Extra Credit**

Option 9.	Check to see if the ASEA currently resembles a complete graph **Extra Credit**


**You must use the following Graph Class Definition:**
```
const int nmax = 100;
class Graph
{
   public:
	graph(int v);
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
 
    //other member functions, if needed

  private: 
    //other private member functions, if needed
    int n; // no. of vertices
	int matrix[nmax][nmax];
	bool visited[nmax];
};
```

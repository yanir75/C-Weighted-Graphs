# C-Graphs

In this project we will receive a directed graph and activates few functions.  
The graph will be represented as a list of vertices and a list of edges for each vertex.
I created a structs for priority queue,list,node and edge to complete this task.

1. Graph creations, upon receiving the letter A followed by the number of vertices in a graph.  
We will start creating a graph in chronological order, every time we would like to work on another vertices we will insert the letter n.   
We will insert the vertex number, then to add an edge we will enter 2 numbers destination vertex and weight, can be done multiple times.  
For example this input: A 4 n 0 2 5 3 3 n 2 0 4 1 1 n 1 3 7 0 2 will create a graph.  
4 vertices  
Vertex 0 will have 2 edges, 0 to 2 with weight of 5 and 0 to 3 with weight of 2.  
Vertex 2 will have 2 edges, 2 to 0 with weight of 4, 2 to 1 with weight of 1.  
Vertex 1 will have 2 edges, 1 to 3 with weight of 7, 1 to 0 with weight of 2.

2. Adding a vertex, upon receiving the letter B followed by a vertex number and edges (same representation as 1).  
  We will create a new vertex and add it to the graph.  
  For example the following input: B 5 0 4 2 1 will create a new vertex and add it to the current graph.  
  Vertex 5 with an edge to 0 with weight of 4 and edge to 2 with weight of 1.  
  In case the vertex already exists it will remove the current one and add the new one.  

3. Removing a vertex, upon receiving the letter D followed by a number we will delete that vertex.
  For example the input: D 2 will delete the vertex number 2.

4. Shortest path, upon receiving the letter S followed by a pair of vertices, will return the shortest path from the first vertex to the second one.  
  For example the input: S 2 0 will return the shortest path from vertex 2 to 0.  
  We used Dijikstra's algorithm. [Explenation on Dijikstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)

5. TSP, upon receiving the letter T followed by a number of vertices and the vertices we will return the shortest path that goes through all the given vertices.  
  For example the input: T 3 0 2 5 will return the shortest path that goes through 0 2 5.  
  This function's complexity is o(n!) n number of vertexes.
  

------------
gcc and make are required.
First lets clone the repository
```
git clone https://github.com/yanir75/C-Weighted-Graphs.git
```
Use the makefile
```
make all
```
Run the program
```
./algo.o
```

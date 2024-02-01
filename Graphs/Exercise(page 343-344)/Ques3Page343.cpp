
/*

In order for us to decide which representation is suitable for graphs to be stored on a disk, 
we need to understand that it depends on the graph. If the graph is sparse, meaning the edges are not a lot, 
then we can store it simply in a adjaceny list. 
The space complexity for Adjacency matrix will be O(n^2) and for adjacency list will be O(n+m) where n is the number of nodes 
and m is the number of edges. So if the data doesn't have a lot of edges, 
using a list would be much better option otherwise using a matrix would be a lot better for a dense graph(complete graph).

*/

#include <iostream>
#include <list>

using namespace std;

//We are assuming that we need to be space efficient so using a list would be a much better option so we are making an adjacency list

class Graph { //class Graph will contain all the vertices


  int V;  //vertex value
  list<int> *adjListPointer; //pointer to the list of array

public:

    Graph(int V) { //constructor

    this->V = V; 
    adjListPointer = new list<int>[V]; //creating a list of array of size V
  }

  void addEdge(int source, int dest){

    adjListPointer[source].push_back(dest);
    adjListPointer[dest].push_back(source); //assuming the graph is undirected
  }

  
};

int main()

{
   Graph g(4); //graph of 4 vertices; 

   g.addEdge(0,1);
   g.addEdge(1,2);
}


/*

Algorithm which reads in a graph and creates its adjacency matrix will be: 

       Assuming that the input of the graph is in the form of a text file, we will read in the file 
and store the data in a matrix.Since we are storing the data in adjaceny list,
we will just need to convert it to adjacency matrix. So we will create a 2d matrix say adjMatrix[v][v] 
which is the total size of the adj matrix. Note v is the number of vertices. 

       Steps: 

       1. Initialize the entire matrix to 0
       2. Loop through each list inside the adj list one by one. 
If say adj[0] has 3 neighbors, then we will make adj[0][1] = 1, adj[0][2] = 1, adj[0][3] = 1. Similarly for adj[1], till adj n
       3. return the adj matrix     
*/

/*
for the third part :::

The above code creates an adj list when given a source and dest vertex
*/


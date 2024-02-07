
// This solution is same for the Question1, Question2, Question3, Question4 and
// Question5.

#include <iostream>
#include <list>
#include <map>
#include <queue>

using namespace std;

class Graph {

public:
  int val;
  list<int> *adj;
  map<int, bool>
      markVisited; // map to store the adj vertex and to see if visited or not.
  queue<int> bfsQ; // queue to store the bfs traversal.

  Graph(int V) {
    this->val = V;
    adj = new list<int>[V];
  }

  void addEdge(int src, int dest) // function to add an edge to the graph
                                  // assuming this is an undirected graph.
  {
    adj[src].push_back(dest);
    adj[dest].push_back(src);
  }

  void printGraph() {
    cout << "Original Graph: " << endl;
    for (int i = 0; i < val; i++) {
      cout << i << " -> ";
      for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
        cout << *it << " ";
      }
      cout << endl;
    }
  }
};

void DFS_adjMatrix(int startVertex, vector<vector<int>> &adjMatrix,
                   vector<bool> &visited) {
  visited[startVertex] = true; // mark the inital visited vertex to true
  cout << startVertex << " ";

  for (auto i = 0; i < adjMatrix.size(); i++) {
    if (adjMatrix[startVertex][i] && !visited[i]) {
      visited[startVertex] = true;
      DFS_adjMatrix(i, adjMatrix, visited);
    }
  }
}

void BFS_adjMatrix(int startVertex, vector<vector<int>> &adjMatrix,
                   vector<bool> &visited, Graph g) {
  fill(visited.begin(), visited.end(),
       false); // Set all values in visited to false

  visited[startVertex] = true; // Mark the starting vertex as visited

  g.bfsQ.push(startVertex);

  while (!g.bfsQ.empty()) {
    int s = g.bfsQ.front();

    cout << s << " ";
    g.bfsQ.pop();

    for (auto i = 0; i < adjMatrix.size(); i++) {
      if (adjMatrix[s][i] && !visited[i]) {
        visited[s] = true;
        g.bfsQ.push(i);
      }
    }
  }
}
// Calling DFS on the garph
void DFS(int startVertex, Graph g) // DFS function which has a start vertex;
{
  g.markVisited[startVertex] = true; // mark the start vertex as visited;
  cout << startVertex << " "; // print the vertices as they are visited in order

  for (auto i = g.adj[startVertex].begin(); i != g.adj[startVertex].end();
       i++) // loop through the adj list for ecah vertex
  {
    if (!g.markVisited[*i]) // if the visited vertex is not marked true,
    {
      g.markVisited[*i] = true; // mark it true
      DFS(*i, g);               // recursively call DFS on that new vertex;
    }
  }
}

// calling BFS on the graph;
void BFS(int startVertex, Graph g) {

  g.markVisited = {}; // clear the mark visited

  g.markVisited[startVertex] = true; // mark the start vertex as visited;
  g.bfsQ.push(startVertex);          // push the starting vertex into the queue;

  while (!g.bfsQ.empty()) // while the queue is not empty)
  {
    int s = g.bfsQ.front();
    cout << s << " ";
    g.bfsQ.pop(); // pop the front

    for (auto i : g.adj[s]) // iterate through the
    {
      if (!g.markVisited[i]) // if it is not marked visited
      {
        g.markVisited[i] = true;
        g.bfsQ.push(i);
      }
    }
  }
}

int main() {

  Graph g(4); // create instance for graph (4 vertices)

  // Just using a simple undirected graph here:

  /*
    0 ---- 2
    |      |
    |      |
    1 ---- 3
  */

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3);
  g.addEdge(3, 2);

  vector<vector<int>> adjMatrix = {
      {0, 1, 1, 0}, {1, 0, 0, 1}, {1, 0, 0, 1}, {0, 1, 1, 0}};

  vector<bool> visited(
      4, false); // Initialize visited array of 4 vertices all to false;

  g.printGraph();

  cout << endl << "DFS Traversal Adjacency Matrix: " << endl;
  DFS_adjMatrix(0, adjMatrix, visited);

  cout << endl << endl << "DFS Traversal Adjacency List: " << endl;
  DFS(0, g); // calling DFS on the graph with initial vertex from 0

  cout << endl << endl << "BFS Traversal Adjacency List: " << endl;
  BFS(0, g); // calling BFS on the graph with initial vertex from 0

  cout << endl<< endl << "BFS Traversal Adjacency Matrix: " << endl;
  BFS_adjMatrix(0, adjMatrix, visited, g);

 /* Original Graph: 
  0 -> 1 2 
  1 -> 0 3 
  2 -> 0 3 
  3 -> 1 2 

  DFS Traversal Adjacency Matrix: 
  0 1 3 2 

  DFS Traversal Adjacency List: 
  0 1 3 2 2 3 

  BFS Traversal Adjacency List: 
  0 1 2 3 

  BFS Traversal Adjacency Matrix: 
  0 1 2 3 3 
   */

}

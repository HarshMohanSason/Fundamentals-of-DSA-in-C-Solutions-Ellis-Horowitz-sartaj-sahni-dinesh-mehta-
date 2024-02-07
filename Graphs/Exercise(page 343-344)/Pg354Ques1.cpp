
#include <iostream> 
#include <list> 
#include <map>
#include <queue> 


using namespace std; 


class Graph{

public: 

  int val; 
  list<int> * adj;
  map<int, bool> markVisited; //map to store the adj vertex and to see if visited or not. 
  queue<int> bfsQ; //queue to store the bfs traversal.

  Graph(int V)
  {
  this->val = V; 
  adj = new list<int>[V];
  }

  void addEdge(int src, int dest)     //function to add an edge to the graph assuming this is an undirected graph. 
  {
  adj[src].push_back(dest);
  adj[dest].push_back(src);
  } 

  void printGraph()   
  {
   cout<<"Original Graph: " <<endl; 
   for(int i = 0; i< val; i++)
     {
       cout<<i<<" -> ";
       for(auto it = adj[i].begin(); it != adj[i].end(); it++)
         {
           cout << *it << " ";
           
         }
       cout<<endl;
     }
  }


};


//Calling DFS on the garph 
void DFS(int startVertex, Graph g) //DFS function which has a start vertex; 
{ 
  g.markVisited[startVertex] = true; //mark the start vertex as visited;
   cout<<startVertex<<" ";  //print the vertices as they are visited in order

 for(auto i = g.adj[startVertex].begin(); i != g.adj[startVertex].end(); i++) //loop through the adj list for ecah vertex
   {
     if(!g.markVisited[*i]) //if the visited vertex is not marked true, 
     {
       g.markVisited[*i] = true;  //mark it true
       DFS(*i, g); //recursively call DFS on that new vertex; 
     }
   }
}

//calling BFS on the graph; 
void BFS(int startVertex, Graph g){

  g.markVisited = {}; //clear the mark visited 

  g.bfsQ.push(startVertex); //push the starting vertex into the queue; 

  while(!g.bfsQ.empty()) //while the queue is not empty)
    {
      int s = g.bfsQ.front();  
      cout<<s << " ";
      g.bfsQ.pop(); //pop the front

      for(auto i: g.adj[s]) //iterate through the 
        {
          if(!g.markVisited[i]) //if it is not marked visited
          {
            g.markVisited[i] = true; 
            g.bfsQ.push(i);
          }
        }
    }
  
}

int main()
{

  Graph g(4); //create instance for graph (4 vertices)

  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 3); 
  g.addEdge(3, 2);

  //Just using a simple undirected graph here:

   /*
     0 ---- 2
     |      |
     |      |
     1 ---- 3
   */

  g.printGraph(); 

 cout<<endl<<"DFS Traversal: "<<endl;
 DFS(0, g); //calling DFS on the graph with initial vertex from 0 

 cout<<endl<<endl<<"BFS Traversal: "<<endl;
 BFS(0, g); //calling BFS on the graph with initial vertex from 0


 /* 
 Output: 
 
 Original Graph: 
 0 -> 1 2 
 1 -> 0 3 
 2 -> 0 3 
 3 -> 1 2 

 DFS Traversal: 
 0 1 3 2 2 3 

 BFS Traversal: 
 0 1 2 0 3 
 
 */
  
}

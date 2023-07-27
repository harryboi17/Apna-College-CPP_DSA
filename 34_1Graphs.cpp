#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define forr(i,s,e) for(int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

/*
DFS(Depth First Search) :
1.) Pre-Order  : First time when call comes on the node.
2.) In-Order   : When the call works inside the subtree.
3.) Post_Order : After working on the subtree, call comes back on the node.
                 After this the call won't come back on the same node.

Note : implemented Using stacks.

BFS(Breath First Search) :
Implemented using queues.


Diff Properties of Graph :
1) Values are associated with nodes.
2) Values are associated with edges.
*/


/*
***************************GRAPH TERMINOLOGIES*************************
1.) Directed Graphs   : Graph with directed edges is known as directed graphs.
2.) Undrirected Graph : Adjecent Vertices with direct edge connecting them.

Degree of Vertex :
1.) Indegree  : No. of incoming edges to a node.
2.) Outdegree : No. of outgoing edges to a node.

Connected Graph:                                    Disconnected Graph:
1) each node has a path from every other node       1) each  node doesn't have a path from every other node

Tree: tree is connected Acyclic graphs.

Complete Graph : A graph in which each vertex is connected to every other vertex by a direct edge
*/
int main(){



return 0;
}
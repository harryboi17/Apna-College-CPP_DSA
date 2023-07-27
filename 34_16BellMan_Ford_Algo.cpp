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
5 8    //all edges are directed
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
0 2 4
4 3 -3
0 1 -1
0
*/
const int INF = 1e9;

int main(){
int n, m;
cin>>n>>m;

vector<vi> edges;
forr(i,0,m){
    int u ,v, w;
    cin>>u>>v>>w;

    edges.pb({u,v,w});
}
int src; cin>>src;
vi dist(n, INF);
dist[src] = 0;

forr(i,0,n-1){  //if you want to detect negetive cycle, make a for loop after n-1 iterations
                //if the value of dist is still changing, that means negetive cycle exists
    for(auto e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        dist[v] = min(dist[v], w + dist[u]);
    }
}

forr(i,0,n){
    cout<<i<<" "<<dist[i]<<endl;
}
return 0;
}

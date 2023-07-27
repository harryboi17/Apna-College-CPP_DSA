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

const int N = 1e5+2;
vi adj[N];

int main(){
int n, m; // n = No. of Nodes  m = No. of Edges
cin>>n>>m;

vector<vi> adjm(n+1, vi(n+1,0));

forr(i,0,m){
    int x, y;
    cin>>x>>y;

    adjm[x][y] = 1;
    adjm[y][x] = 1;
}

cout<<"The adjacent matrix of the above graph is : "<<endl;
forr(i,1,n+1){
    forr(j,1,n+1)
        cout<<adjm[i][j]<<" ";
    cout<<endl;
}cout<<endl;

if(adjm[3][7] == 1)
    cout<<"There is a edge between 3 and 7"<<endl;
else
    cout<<"No Edge"<<endl;
cout<<endl;

cin>>n>>m;
forr(i,0,m){
    int x,y;
    cin>>x>>y;

    adj[x].push_back(y);
    adj[y].push_back(x);
}

cout<<endl<<"adjacency List of the above graph is : "<<endl;
forr(i,1,n+1){
    cout<<i<<" -> ";
    for(int x : adj[i])
        cout<<x<<" ";
    cout<<endl;
}

return 0;
}
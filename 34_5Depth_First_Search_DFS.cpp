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
bool vis[N];

void DFS(int node){
    //preorder
    vis[node] = 1;
    cout<<node<<" ";

    //inorder
    for(auto i : adj[node])
        if(!vis[i])
            DFS(i);

    //postOrder
    // cout<<node<<" "; //this if unHASH this and HASH the cout in preorder
                        //we will get postOrder sequence  

}

int main(){
    forr(i,0,N)
        vis[i] = false;

    int n, m;
    cin>>n>>m;

    forr(i,0,m){
        int x,y;
        cin>>x>>y;

        adj[x].pb(y);
        adj[y].pb(x);
    }
    DFS(1);
return 0;
}
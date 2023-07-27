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

bool Iscycle(int src, vector<vi> &adj, vector<bool> &vis, vi &stack){
    stack[src] = true;
    if(!vis[src]){
        vis[src] = true;
        for(auto i : adj[src]){
            if(!vis[i] && Iscycle(i, adj, vis, stack))
                return true;
            if(stack[i])
                return true;
        }
    }
    stack[src] = false;
    return false;
}

int main(){
int n, m;
cin>>n>>m;

vector<vi> adj(n+1);
forr(i,0,m){
    int x,y;
    cin>>x>>y;
    adj[x].pb(y);
}

bool cycle = false;
vi stack(n+1,0);
vector<bool> vis(n+1, false);

forr(i,1,n+1)
    if(!vis[i] && Iscycle(i, adj, vis, stack))
        cycle = true;

if(cycle)
    cout<<"Cycle is present"<<endl;
else
    cout<<"Cycle is not present"<<endl;
return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define forr(i, s, e) for (int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr) / sizeof(arr[0])
using namespace std;

vector<bool> vis;
vector<vi> adj;
vi col;
bool bipart;

void color(int u, int curr){
    if(col[u] != -1 && col[u] != curr){
        bipart = false; 
        return;
    }

    col[u] = curr;
    if(vis[u])
        return;
    vis[u] = true;
    for(auto i : adj[u])
        color(i, curr xor 1);
}

int main()
{
    bipart = true;
    int n, m;
    cin >> n >> m;

    adj = vector<vi>(n+1);
    vis = vector<bool>(n+1 , false);
    col = vi(n+1, -1);

    forr(i, 0, m){
        int x, y;
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    forr(i, 1, n + 1)
        if (!vis[i])
            color(i,0);
    
    if(bipart)
        cout<<"The graph is a biparted graph"<<endl;
    else
        cout<<"The graph is not a biparted graph"<<endl;

    return 0;
}
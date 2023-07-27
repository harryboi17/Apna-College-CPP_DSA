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

bool iscycle(int src, vi adj[], bool vis[], int parent)
{
    vis[src] = true;
    for (auto i : adj[src]){
        if (i != parent){
            if (vis[i])
                return true;
            if (!vis[i] && iscycle(i, adj, vis, src))
                return true;
        }
    }
    return false;
}

const int N = 1e5 + 2;
vi adj[N];
bool vis[N];

int main()
{
    forr(i, 0, N)
        vis[i] = false;

    int n, m;
    cin >> n >> m;

    forr(i, 0, m){
        int x, y;
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    bool cycle = false;
    forr(i, 1, n + 1) 
        if (!vis[i] && iscycle(i, adj, vis, -1))
            cycle = true;

    if (cycle)
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle is not present" << endl;
    return 0;
}
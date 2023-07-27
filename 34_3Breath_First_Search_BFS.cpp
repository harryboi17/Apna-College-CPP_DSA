#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define forr(i, s, e) for (int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr) / sizeof(arr[0])
using namespace std;

const int N = 1e5 + 2;
vi adj[N];
bool vis[N];

int main()
{
    forr(i,0,N)
        vis[i] = 0;

    int n, m;
    cin >> n >> m;

    forr(i, 0, m){
        int x, y;
        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);
    }

    queue<int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto i : adj[node]){
            if (!vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    
    return 0;
}
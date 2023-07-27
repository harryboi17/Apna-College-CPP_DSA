#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
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
4 5
0 1 40
1 2 15
0 2 5
3 1 2
3 2 10
*/
const int N = 1e5+3;
int cost = 0;
vi dist(N), parent(N);
vector<pii> g[N];
vector<bool> vis(N);

const int INF = 1e9;
void primsMST(int src){
    forr(i,0,N)
        dist[i] = INF;
    
    set<vi> s;
    dist[src] = 0;
    s.insert({0,src});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);

        vis[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout<<u<<" "<<v<<" "<<w<<endl;
        cost += w;
        for(auto it : g[x[1]]){
            if(vis[it.ff])
                continue;
            if(dist[it.ff] > it.ss){
                s.erase({dist[it.ff], it.ff});
                dist[it.ff] = it.ss;
                s.insert({dist[it.ff], it.ff});
                parent[it.ff] = x[1];
            }
        }
    }
}

int main(){
int n, m;
cin>>n>>m;

forr(i,0,m){
    int x, y, w;
    cin>>x>>y>>w;

    g[x].pb({y,w});
    g[y].pb({x,w});
}
primsMST(0);
cout<<cost<<endl;


return 0;
}
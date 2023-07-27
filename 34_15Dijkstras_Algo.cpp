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
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1
*/
int main(){
int INF = 1e9;
int n, m;
cin>>n>>m;

vector<vector<pii>> graph(n+1);
vi dist(n+1, INF);
set<pii> s;

forr(i,0,m){
    int x, y, w;
    cin>>x>>y>>w;

    graph[x].pb({y,w});
    graph[y].pb({x,w});
}

int source; cin>>source;
dist[source] = 0;
s.insert({0, source});

while(!s.empty()){
    auto x = *(s.begin());
    s.erase(x);

    for(auto it : graph[x.ss]){
        if(dist[it.first] > dist[x.ss] + it.ss){
            s.erase({dist[it.first], it.first});
            dist[it.ff] = dist[x.ss] + it.ss;
            s.insert({dist[it.first], it.first});
        }
    }
}
forr(i,1,n+1){
    if(dist[i] < INF)
        cout<<i<<" "<<dist[i]<<endl;
    else 
        cout<<"cannot reach "<<i<<endl;
}

return 0;
}
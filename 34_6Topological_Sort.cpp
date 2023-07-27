#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#define forr(i,s,e) for(int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;
//doesn't work with cyclic graphs, as there is no initialization point who has a indegree 0.
const int N = 1e5+2;
vi adj[N];
bool vis[N];

int main(){
forr(i,0,N)
    vis[i] = false;

int n, m;
cin>>n>>m;

vi in_deg(n+1,0);
forr(i,0,m){
    int x,y;
    cin>>x>>y;

    adj[x].pb(y);
    in_deg[y]++;
}

queue<int> pq;
forr(i,1,n+1)
    if(in_deg[i] == 0)
        pq.push(i);

int cnt = 0;
while (!pq.empty())
{
    cnt++;
    int x = pq.front();
    pq.pop();
    cout<<x<<" ";

    for(auto i : adj[x]){
        in_deg[i]--;
        if(in_deg[i] == 0)
            pq.push(i);
    }   
}
return 0;
}
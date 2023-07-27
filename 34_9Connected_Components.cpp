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

int get_comp(int idx, int vis[], vi adj[]){
    if(vis[idx])
        return 0;
    vis[idx] = 1;
    int ans = 1;
    for(auto i : adj[idx])
        if(!vis[i]){
            ans += get_comp(i, vis, adj);
            vis[i] = 1;
        }
    return ans;
}

int main(){
int n, m;
cin>>n>>m;
vi adj[n+1];
int vis[n+1] = {0};
vi components;

forr(i,0,m){
    int x, y;
    cin>>x>>y;

    adj[x].pb(y);
    adj[y].pb(x);
}

forr(i,1,n+1)
    if(!vis[i])
        components.pb(get_comp(i, vis, adj));
    
for(auto i : components)
    cout<<i<<" ";
cout<<endl;

//Q. No of ways you can choose 2 nodes which are not connected in anyway
//to solve we will choose any 2 components and multiply there size

int answer = 0;
for(auto i : components)
    answer += i*(n-i);
cout<<answer/2<<endl;
return 0;
}
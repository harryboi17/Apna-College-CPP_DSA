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

const int N = 1e5+6;
int parent[N];
int size[N];

void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        if(size[a] < size[b])
            swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    forr(i,0,N)
        make_set(i);

    int n, m;
    cin>>n>>m;
    vector<vi> edges;

    forr(i,0,m){
        int x, y; 
        cin>>x>>y;
        edges.pb({x,y});
    }

    bool cycle = false;
    for(auto i : edges){
        int u = i[0];
        int v = i[1];

        int x = find_set(u);
        int y = find_set(v);
        if(x == y)
            cycle = true;
        else
            union_sets(u,v);
    }

    if(cycle)
        cout<<"Cycle is present"<<endl;  
    else
        cout<<"Cycle is not present"<<endl;

return 0;
}
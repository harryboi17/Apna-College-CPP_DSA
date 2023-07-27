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
/*
8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1
8 5 1
*/
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
        int u, v, w;
        cin>>u>>v>>w;
        edges.pb({w,u,v});
    }
    sort(edges.begin(), edges.end());

    int cost = 0;
    for(auto i : edges){
        int w = i[0];
        int u = i[1];
        int v = i[2];

        int x = find_set(u);
        int y = find_set(v);
        if(x == y)
            continue;
        else{
            cout<<u<<" "<<v<<endl;
            cost += w;
            union_sets(u,v);
        }
    }
    cout<<cost;

return 0;
}
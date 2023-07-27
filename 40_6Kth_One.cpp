#include <iostream>
#include <vector>
#include <limits.h>
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
5 7
1 1 0 1 0 
2 0
2 1
2 2
1 2
2 3
1 0
2 0
*/
const int N = 1e5 + 2;
int arr[N];
int trees[N*4];

void build(int node, int st, int en){ //built in O(2n -1) time
    if(st == en){
        trees[node] = arr[st];
        return;
    }

    int mid = (st+en)/2;
    build(2*node, st, mid);
    build(2*node + 1, mid+1, en);

    trees[node] = trees[2*node] + trees[2*node + 1];
}

int query(int node, int st, int en, int k){ //done in log(n) time
    if(st == en)
        return st;
    
    int mid = (st + en)/2;

    if(k < trees[2*node])
        return query(2*node, st, mid, k);
    else{
        k -= trees[2*node];
        return query(2*node + 1, mid+1, en, k);
    }
}

void update(int node, int st, int en, int idx){
    if(st == en && st == idx){
        arr[st] = arr[st] xor 1;
        trees[node]= arr[st];
        return;
    }

    int mid = (st + en)/2;
    if(mid >= idx)
        update(2*node, st, mid, idx);
    else
        update(2*node + 1, mid+1, en, idx);

    trees[node] = trees[2*node] + trees[2*node + 1];
}

int main(){
int n, m;
cin>>n>>m;

forr(i,0,n)
    cin>>arr[i];

build(1, 0, n-1);
while(m--){
    int type; cin>>type;
    if(type == 1){
        int idx; cin>>idx;
        update(1, 0, n-1, idx);
    }
    if(type == 2){
        int k; cin>>k;
        cout<<query(1, 0, n-1, k)<<endl;
    }
}

return 0;
}
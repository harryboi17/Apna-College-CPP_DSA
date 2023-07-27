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
const int N = 1e5+2;
int trees[4*N];
int arr[N];
/*
9
6 8 -1 2 17 1 3 2 4
1
1 3
2
7 18
-1
*/

void build(int node, int st, int en){ //built in O(2n -1) time
    if(st == en){
        trees[node] = arr[st];
        return;
    }

    int mid = (st+en)/2;
    build(2*node, st, mid);
    build(2*node + 1, mid+1, en);

    trees[node] = max(trees[2*node], trees[2*node + 1]);
}

int query(int node, int st, int en, int l, int r){ //done in log(n) time
    if(st > r || en < l)
        return INT_MIN;
    
    if(l <= st && r >= en) // l... st...en ...r
        return trees[node];
    
    int mid = (st + en)/2;

    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node + 1, mid+1, en, l, r);

    return max(q1, q2);
}

void update(int node, int st, int en, int idx, int val){
    if(st == en && st == idx){
        arr[st] = val;
        trees[node] = val;
        return;
    }

    int mid = (st + en)/2;
    if(mid >= idx)
        update(2*node, st, mid, idx, val);
    else
        update(2*node + 1, mid+1, en, idx, val);

    trees[node] = max(trees[2*node], trees[2*node + 1]);
}

int main(){
int n; cin>>n;
forr(i,0,n)
    cin>>arr[i];

build(1, 0, n-1);
// forr(i,1,2*n)
//     cout<<trees[i]<<" ";
// cout<<endl;

while(1){
    int type; cin>>type;
    if(type == -1)
        break;
    if(type == 1){
        int l, r;
        cin>>l>>r;
        cout<<query(1, 0, n-1, l, r)<<endl;
    }
    if(type == 2){
        int idx, val;
        cin>>idx>>val;
        update(1, 0, n-1, idx, val);
        // forr(i,1,2*n)
        //     cout<<trees[i]<<" ";
        // cout<<endl;
    }
}

return 0;
}
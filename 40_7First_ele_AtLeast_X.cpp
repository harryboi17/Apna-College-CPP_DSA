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

const int N = 1e5 + 2;
int arr[N], trees[N*4];

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
int n, m;
cin>>n>>m;

forr(i,0,n)
    cin>>arr[i];

build(1, 0, n-1);
while(m--){
    int type; cin>>type;
    if(type == 1){
        int idx, val; 
        cin>>idx>>val;
        update(1, 0, n-1, idx, val);
    }
    if(type == 2){
        int x, l;
        cin>>x>>l; //a[j] >= x && j >= l
        int lo = l, hi = n-1;
        int ans = n;
        while(lo <= hi){
            int mid = (lo + hi)/2;
            if(query(1, 0, n-1, lo, mid) < x)
                lo = mid + 1;
            else{
                hi = mid - 1;
                ans = min(ans, mid);
            }
        }

        if(ans == n)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
    }
}

return 0;
}
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
5 3
0 1 7
2 4 6
1 3 2
3
0 3 4
*/
int query(int i, int bit[], int n){
    int ans = 0;
    while(i > 0){
        ans += bit[i];
        i -= i & (-i);
    }
    return ans;
}

void update(int i, int inc, int bit[], int n){
    while(i <= n){
        bit[i] += inc;
        i += i & (-i);
    }
}

int main(){
int n; cin>>n;
int bit[n+10] = {0};

int u; cin>>u;
while(u--){
    int l, r, inc;
    cin>>l>>r>>inc;
    l++; r++;
    update(l, inc, bit, n);
    update(r+1, -inc, bit, n);
}

int q; cin>>q;
while(q--){
    int w; cin>>w;
    w++;
    cout<<query(q, bit, n)<<endl;
}

return 0;
}
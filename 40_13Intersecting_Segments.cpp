#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
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
finding segements which are not inrtersecting with other segement and not lying inside it

to find it, we will use Nested Segment to find the number of segments lying inside it
and then to find nested_segment we will subtract its douible by number of number between the segment

nested_segment = number of segements - 2*nested segements
*/
/*
5
5 1 2 2 3 1 3 4 5 4
*/
const int N = 1e5 + 2;
int trees[N*4];

int query(int node, int st, int en, int l, int r){ //done in log(n) time
    if(st > r || en < l)
        return 0;
    
    if(l <= st && r >= en) // l... st...en ...r
        return trees[node];
    
    int mid = (st + en)/2;

    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node + 1, mid+1, en, l, r);

    return q1 + q2;
}

void update(int node, int st, int en, int idx, int val){
    if(st == en && st == idx){
        trees[node] = val;
        return;
    }

    int mid = (st + en)/2;
    if(mid >= idx)
        update(2*node, st, mid, idx, val);
    else
        update(2*node + 1, mid+1, en, idx, val);

    trees[node] = trees[2*node] + trees[2*node + 1];
}

int main(){
int n; cin>>n;
int arr[2*n];
forr(i, 0, 2*n)
    cin>>arr[i];

unordered_map<int, int> m;
vector<pair<pii, int>> range(n+1);
range[0] = {{0,0}, 0};
forr(i,0,2*n){
    if(m[arr[i]]++)
        range[arr[i]].ff.ss = i;
    else
        range[arr[i]].ff.ff = i;
    range[arr[i]].ss = arr[i];
}

sort(range.begin(), range.end(), [&](pair<pii, int> a, pair<pii, int> b){
    return a.ff.ss < b.ff.ss;
});

vi nested_segment(n);
forr(i,1, n+1){
    nested_segment[range[i].ss - 1] = query(1, 0, 2*n - 1, range[i].ff.ff, range[i].ff.ss);
    update(1, 0, 2*n -1, range[i].ff.ff, 1);
}

vi total_num(n+1);
forr(i,1,n+1)
    total_num[range[i].ss - 1] = range[i].ff.ss - range[i].ff.ff - 1; 

vi ans(n);
forr(i,0,n)
    ans[i] = total_num[i] - (2*nested_segment[i]);

forr(i,0,n)
    cout<<total_num[i]<<" ";
cout<<endl;

forr(i,0,n)
    cout<<nested_segment[i]<<" ";
cout<<endl;

forr(i,0,n)
    cout<<ans[i]<<" ";
cout<<endl;
return 0;
}
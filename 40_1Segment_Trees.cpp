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
const int N = 1e5+2;
int trees[4*N];
int arr[N];

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

int query(int node, int st, int en, int l, int r){ //done in log(n) time
    if(st > r || en < l)
        return 0;
    
    if(l <= st && r >= en) // l... st...en ...r
        return trees[node];
    
    int mid = (st + en)/2;

    int q1 = query(2*node, st, mid, l, r);
    int q2 = query(2*node + 1, mid+1, en, l, r);

    return q1+q2;
}

int main(){
int n; cin>>n;
forr(i,0,n)
    cin>>arr[i];

build(1, 0, n-1);
forr(i,1,2*n)
    cout<<trees[i]<<" ";
cout<<endl;

while(1){
    int type;
    cout<<"Enter the type : "; cin>>type;
    if(type == -1)
        break;
    if(type == 1){
        int l, r;
        cin>>l>>r;
        cout<<query(1, 0, n-1, l, r)<<endl;
    }
}

return 0;
}
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

class grp{
    public:
        long pref, suff, ans, sum;
        grp(long pref, long suff, long sum, long ans){
            this->pref = pref;
            this->suff = suff;
            this->sum = sum;
            this->ans = ans;
        }
};

const int N = 1e5+2;
long arr[N]; grp *tree[4*N];

void build(int node, int st, int en){
    if(st == en){
        if(arr[st] <= 0)
            tree[node] = new grp(0,0,arr[st],0);
        else
            tree[node] = new grp(arr[st], arr[st], arr[st], arr[st]);
        return;
    }

    int mid = (st + en)/2;
    build(2*node, st, mid);
    build(2*node + 1, mid+1, en);

    long sum = tree[2*node]->sum + tree[2*node + 1]->sum;
    long pref = max(tree[2*node]->pref, tree[2*node]->sum + tree[2*node + 1]->pref);
    long suff = max(tree[2*node + 1]->suff, tree[2*node]->suff + tree[2*node + 1]->sum);
    long ans = max({tree[2*node]->ans, tree[2*node + 1]->ans, tree[2*node]->suff + tree[2*node + 1]->pref});

    tree[node] = new grp(pref, suff, sum, ans);
}

void update(int node, int st, int en, int idx, int val){
    if(st == en && st == idx){
        arr[idx] = val;
        if(arr[st] <= 0)
            tree[node] = new grp(0,0,arr[st],0);
        else
            tree[node] = new grp(arr[st], arr[st], arr[st], arr[st]);
        return;
    }

    int mid = (st + en)/2;
    if(mid >= idx)
        update(2*node, st, mid, idx, val);
    else
        update(2*node + 1, mid+1, en, idx, val);

    long sum = tree[2*node]->sum + tree[2*node + 1]->sum;
    long pref = max(tree[2*node]->pref, tree[2*node]->sum + tree[2*node + 1]->pref);
    long suff = max(tree[2*node + 1]->suff, tree[2*node]->suff + tree[2*node + 1]->sum);
    long ans = max({tree[2*node]->ans, tree[2*node + 1]->ans, tree[2*node]->suff + tree[2*node + 1]->pref});

    tree[node] = new grp(pref, suff, sum, ans);
}
int main(){
    int n, m;
    cin>>n>>m;
    forr(i,0,n)
        cin>>arr[i];
    
    build(1, 0, n-1);
    cout<<tree[1]->ans<<endl;

    while(m--){
        int idx, val;
        cin>>idx>>val;

        update(1, 0, n-1, idx, val);
        cout<<tree[1]->ans<<endl;
    }

return 0;
}
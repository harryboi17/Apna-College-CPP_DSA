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
11
1 1 2 1 3 3 4 1 2 4 3
3
1 6
5 11
3 6
*/
const int N = 2e5+2;
int rootN;

struct Q{
    int idx, l, r;
};
Q q[N];

bool compare(Q  q1, Q q2){
    if(q1.l/rootN == q2.l/rootN)
        return q1.r > q2.r;
    return q1.l/rootN < q2.l/rootN; 
}

int main(){
int n; cin>>n;
vi a(n);
forr(i,0,n)
    cin>>a[i];

rootN = sqrtl(n);
int que; cin>>que;
forr(i,0,que){
    int l, r;
    cin>>l>>r;

    q[i].l = l; 
    q[i].r = r; 
    q[i].idx = i; 
}

sort(q, q+que, compare);
forr(i,0,que)
    cout<<q[i].l<<" "<<q[i].r<<endl;

vi ans(que);
int cur_l = 0, cur_r = -1, l, r;
int cur_ans = 0;
unordered_map<int, int> m;

forr(i,0,que){
    l = q[i].l; r = q[i].r;
    l--; r--;

    while(cur_r < r){
        cur_r++;
        if(!m[a[cur_r]]++)
            cur_ans++;
    }
    while(cur_l > l){
        cur_l--;
        if(!m[a[cur_l]]++)
            cur_ans++;
    }
    while(cur_l < l){
        if(!--m[a[cur_l]])
            cur_ans--;
        cur_l++;
    }
    while(cur_r > r){
        if(!--m[a[cur_r]])
            cur_ans--;
        cur_r--;
    }

    ans[q[i].idx] = cur_ans;
}

for(auto i : ans)
    cout<<i<<endl;

return 0;
}
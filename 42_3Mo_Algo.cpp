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
9
1 5 -2 6 8 -7 2 1 11
3
7 8
1 6
2 7
*/
const int N = 1e5+2;
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

vi ans(que);
int cur_l = 0, cur_r = -1, l, r;
int cur_ans = 0;
forr(i,0,que){
    l = q[i].l; r = q[i].r;
    l--; r--;

    while(cur_r < r){
        cur_r++;
        cur_ans += a[cur_r];
    }
    while(cur_l > l){
        cur_l--;
        cur_ans += a[cur_l];
    }
    while(cur_l < l){
        cur_ans -= a[cur_l];
        cur_l++;
    }
    while(cur_r > r){
        cur_ans -= a[cur_r];
        cur_r--;
    }

    ans[q[i].idx] = cur_ans;
}
/*
Time Complexity : O((n+Q)*sqrt(n))

No. of time cur_l changes value = Q*sqrt(n)
No of times cur_r change value = n*(n/sqrt(n)) = n*root(n)

explanation for cur_r : in a block cur_r can change max to max n time the value, since each block is placed in a sorted order
                        and this step in done in all blocks, that is all root(n) blocks
hence cur_l + cur_r = O(Q*sqrt(n)) + O(n*sqrt(n))
*/
for(auto i : ans)
    cout<<i<<endl;

return 0;
}
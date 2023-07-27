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
LSB : 10 -> 1010 so LSB is 0010
      15 -> 1111 so LSB is 0001
      5  -> 0101 so LSB is 0001

to find LSB of a number lets say a1b where a is a random bit, b is all 0's

taking 2's compilement
a'0b' where b' is all 1's
adding 1 to this will make it a'1b where b is again all 0's
taking and of a'1b and a1b will get the LSB 1b or 0..100..
*/
int n;
vi bit;

void update(int idx, int val){
    while(idx <= n){
        bit[idx] += val;
        idx += idx & (-idx); //adding LSB
    }
}

int query(int idx){
    int ans = 0;
    while(idx > 0){
        ans += bit[idx];
        idx -= idx & (-idx); //subtracting LSB
    }
    return ans;
}

int main(){
cin>>n;
bit = vector<int>(n+1);

vi arr(n+1);
forr(i,1,n+1){
    cin>>arr[i];
    update(i, arr[i]);
}

int q; cin>>q;
while(q--){
    int type; cin>>type;
    if(type == 1){
        int l,r;
        cin>>l>>r;
        int ans = query(r) - query(l-1);
        cout<<ans<<endl;
    }
    if(type == 2){
        int idx, val;
        cin>>idx>>val;
        update(idx, -arr[idx]);
        arr[idx] = val;
        update(idx, val);
    }
}

return 0;
}
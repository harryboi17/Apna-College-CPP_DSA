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
*/
int main(){
int n; cin>>n;
int arr[n];
forr(i,0,n)
    cin>>arr[i];

int len = sqrt(n) + 1;
vi b(len, INT_MAX);

forr(i,0,n)
    b[i/len] = min(b[i/len], arr[i]);

int q; cin>>q;
while(q--){
    int l, r;
    cin>>l>>r;
    l--; r--;

    int minimum = INT_MAX;
    for(int i = l; i <= r;){
        if(i%len == 0 && i + len - 1 <= r){
            minimum = min(minimum, b[i/len]);
            i += len;
        }
        else{
            minimum = min(minimum, arr[i]);
            i++;
        }
    }
    cout<<minimum<<endl;
}
return 0;
}
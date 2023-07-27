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
const int N = 10000;
int dp[N];
int friend_pair(int n){
    if(n == 1 || n == 0)
        return dp[n] = 1;
    return dp[n] = friend_pair(n-1) + ((n-1)*friend_pair(n-2));
}

int main(){
int n; cin>>n;
cout<<friend_pair(n)<<endl;

return 0;
}
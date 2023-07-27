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
const int N = 1e5+6, MOD = 1e9+7;
int dp[N];

int MinSq(int n){
    if(n == 0 || n == 1 || n == 2 || n == 3)
        return n;
    
    if(dp[n] != MOD)
        return dp[n];
    
    for(int i = 1; i*i <= n; i++)
        dp[n]  = min(dp[n], MinSq(n-i*i) + 1);
    
    return dp[n];
}

int main(){
forr(i,0,N)
    dp[i] = MOD;

int n; cin>>n;
cout<<MinSq(n)<<endl; 
return 0;
}
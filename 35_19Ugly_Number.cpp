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
//1, 2, 3, 4, 5, 6, 8, 9, 10, 12 
int main(){
int n; cin>>n;
int dp[n+1];
int c2(0), c3(0), c5(0);
dp[0] = 1;
forr(i,1,n){
    dp[i] = min({2*dp[c2], 3*dp[c3], 5*dp[c5]});
    if(2*dp[c2] == dp[i])
        c2++;
    if(3*dp[c3] == dp[i])
        c3++;
    if(5*dp[c5] == dp[i])
        c5++;
}
cout<<dp[n-1]<<endl;

return 0;
}
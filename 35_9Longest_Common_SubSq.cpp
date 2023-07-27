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
const int N = 1e3+2;
int dp[N][N];

int lcs(string &s1, string &s2, int n, int m){
    if(n == 0 || m == 0)
        return 0;
    
    if(dp[n][m] != -1)
        return dp[n][m];

    if(s1[n-1] == s2[m-1])
        dp[n][m] = 1 + lcs(s1, s2, n-1, m-1);
    else
        dp[n][m] = max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1)); 
    
    return dp[n][m];
}

int main(){
forr(i,0,N)
    forr(j,0,N)
        dp[i][j] = -1;

string s1, s2; cin>>s1>>s2;
int n = s1.size(); int m = s2.size();

cout<<lcs(s1, s2, n, m)<<endl;

return 0;
}
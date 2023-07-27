#include <iostream>
#include <vector>
#include <cstring> 
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
const int N = 201;
int dp[N][N][N];
int LCS(string &s1, string &s2, string &s3, int i, int j, int k){ //Used & reference to prevent use of excess memory by making copies
    if(i == 0 || j == 0 || k == 0)
        return 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];

    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
        return dp[i][j][k] = 1 + LCS(s1, s2, s3, i-1, j-1, k-1);
    else{
        int x = LCS(s1, s2, s3, i-1, j, k);
        int y = LCS(s1, s2, s3, i, j-1, k);
        int z = LCS(s1, s2, s3, i, j, k-1);
        return dp[i][j][k] = max({x,y,z});
    }
}

int main(){
string s1; cin>>s1;
string s2; cin>>s2;
string s3; cin>>s3;

memset(dp, -1, sizeof(dp)); //memset is contained in <cstring> library
cout<<LCS(s1, s2, s3, s1.size(), s2.size(), s3.size())<<endl;

return 0;
}
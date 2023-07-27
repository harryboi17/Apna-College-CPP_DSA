#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits.h>
#define forr(i,s,e) for(int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;
const int N = 1000;
int dp[N][N];

int matrixMult(vector<pii> v, int cut1, int cut2){
    if(cut2 - cut1 == 0)
        return 0;
    if(cut2 - cut1 == 1)
        return 0;
    if(cut2 - cut1 == 2)
        return v[cut1].ff * v[cut1].ss * v[cut2-1].ss;

    if(dp[cut1][cut2] != INT_MAX)
        return dp[cut1][cut2];

    forr(i,cut1+1,cut2){
        dp[cut1][cut2]  = min(dp[cut1][cut2], (matrixMult(v, cut1, i) + matrixMult(v, i, cut2) + (v[cut1].ff * v[i].ff * v[cut2-1].ss)));
    }
    return dp[cut1][cut2];
}

int main(){
forr(i,0,N)
    forr(j,0,N)
        dp[i][j] = INT_MAX;

int n; cin>>n;
vector<pii> v;
forr(i,0,n){
    int x, y;
    cin>>x>>y;
    v.push_back({x,y});
}
cout<<matrixMult(v, 0, n);

return 0;
}
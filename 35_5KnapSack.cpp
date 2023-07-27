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

const int N = 1e5+5;
int wt[] = {15, 30, 45};
int val[] = {60, 100, 150};
const int n = arrSize(wt);
int dp[N][n];

int knapsack(int n, int W){
    if(W == 0 || n == 0)
        return 0;

    if(dp[W][n] != -1)
        return dp[W][n];
    
    if(wt[n-1] > W)
        dp[W][n] = knapsack(n-1, W);
    else
        dp[W][n] = max(knapsack(n-1, W - wt[n-1]) + val[n-1], knapsack(n-1, W));
    
    return dp[W][n];
}

int main(){
forr(i,0,N)
    forr(j,0,n)
        dp[i][j] = -1;

int W; cin>>W;
cout<<knapsack(n, W)<<endl;
return 0;
}
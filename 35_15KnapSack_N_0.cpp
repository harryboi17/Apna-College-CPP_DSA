#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define forr(i, s, e) for (int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr) / sizeof(arr[0])
using namespace std;
const int N = 10000;
vi dp(N,0);

int knapsack(int wt[], int val[], int n, int W)
{
    vector<pair<float, int>> val_by_wt(n);
    forr(i, 0, n)
        val_by_wt[i] = {float(val[i]) / wt[i], i};

    sort(val_by_wt.begin(), val_by_wt.end(), greater<pair<float, int>>());

    // forr(i,0,n)
    //     cout<<val_by_wt[i].ff<<" "<<val_by_wt[i].ss<<endl;

    int ans = 0;
    forr(i, 0, n)
    {
        if (W >= wt[val_by_wt[i].ss])
        {
            ans += (W / wt[val_by_wt[i].ss]) * val[val_by_wt[i].ss];
            W -= (W / wt[val_by_wt[i].ss]) * wt[val_by_wt[i].ss];
        }
    }
    return ans;
}

int byDP(int wt[], int val[], int n, int W){
    forr(j,0,W+1)
        forr(i,0,n)
            if(j - wt[i] >= 0)
                dp[j] = max(dp[j], val[i] + dp[j - wt[i]]);
    
    return dp[W];
}
int main()
{
    int wt[] = {3, 2, 4, 5, 1};
    int val[] = {4, 3, 5, 6, 1};
    int n = arrSize(wt);

    int W; cin >> W;
    cout<<knapsack(wt, val, n, W)<<endl;
    cout<<byDP(wt, val, n, W)<<endl;
    return 0;
}
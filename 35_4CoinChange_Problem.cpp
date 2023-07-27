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

const int N = 1e4 + 7;
int set[] = {3,2,1};
const int n = arrSize(set);
int dp[N][n];

int coinChange(int n, int val)
{
    if (val == 0)
        return 1;
    if (n == 0 || val < 0)
        return 0;

    if (dp[val][n] != -1)
        return dp[val][n];

    dp[val][n] = coinChange(n - 1, val) + coinChange(n , val - set[n - 1]); //first recursion : we didnt took the last coin and skipped
                                                                            //second recursion : we took the last coin and subtracted its value from val
    return dp[val][n];
}

int main()
{
    forr(i, 0, N)
        forr(j, 0, n)
            dp[i][j] = -1;

    cout << coinChange(n, 8) << endl;
    cout << coinChange(n, 7) << endl;
    cout << coinChange(n, 9) << endl;
    cout << coinChange(n, 6) << endl;
    return 0;
}
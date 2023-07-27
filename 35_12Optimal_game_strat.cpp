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
int dp[1000][1000];
int strat(int val[], int first, int last)
{
    if (first == last)
        return val[first];
    if (first > last)
        return 0;

    if (dp[first][last] != -1)
        return dp[first][last];

    int l = val[first] + min(strat(val, first + 2, last), strat(val, first + 1, last - 1));
    int r = val[last] + min(strat(val, first, last - 2), strat(val, first + 1, last - 1));

    return dp[first][last] = max(l, r);
}

int main()
{
    forr(i, 0, 1000)
        forr(j, 0, 1000)
            dp[i][j] = -1;

    int arr[] = {1, 2, 3, 4};
    int n = arrSize(arr);

    cout << strat(arr, 0, n - 1);
    return 0;
}
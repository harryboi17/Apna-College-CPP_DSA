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
const int N = 1e5 + 5;
int dp1[N];
int dp2[N];

int longest_inc_SubSq(int arr[], int n)
{
    if (dp1[n] != -1) 
        return dp1[n];

    dp1[n] = 1;
    forr(i, 0, n)
        if (arr[n] > arr[i])
            dp1[n] = max(dp1[n], 1 + longest_inc_SubSq(arr, i));

    return dp1[n];
}

int longest_dec_SubSq(int arr[], int n)
{
    if (dp2[n] != -1)
        return dp2[n];

    dp2[n] = 1;
    forr(i, 0, n)
        if (arr[n] < arr[i])
            dp2[n] = max(dp2[n], 1 + longest_dec_SubSq(arr, i));

    return dp2[n];
}

int main()
{
    forr(i, 0, N)
        dp1[i] = -1;
    forr(i, 0, N)
        dp2[i] = -1;

    int arr[] = {7, 1, 4, 2, 8, 9, 10, 5, 11};
    int n = arrSize(arr);

    int ans = 0;
    forr(i,0,n)
        ans = max(ans, longest_inc_SubSq(arr, i));
    cout<<ans<<endl;

    forr(i, 0, n)
        cout<< dp1[i] << " ";
    cout<<endl;

    int ans2 = 0;
    forr(i,0,n)
        ans2 = max(ans2, longest_dec_SubSq(arr, i));
    cout<<ans2<<endl;
    forr(i, 0, n)
        cout<< dp2[i] << " ";

    return 0;
}
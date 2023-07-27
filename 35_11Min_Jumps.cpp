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
int dp[N];

int Minjump(int arr[], int n) 
{
    if (n == 0)
        return 0;

    if (dp[n] != 10000)
        return dp[n];

    for (int i = n - 1; i >= 0; i--)
        if (arr[i] >= (n - i))
            dp[n] = min(dp[n], Minjump(arr, i) + 1);

    return dp[n];
}

int min_jump(int arr[], int n) //O(n)
{
    int i = 0, range = 0 + arr[0], new_range = 0, jump = 0, sec_range = 0;

    while (i < n)
    {

        if (arr[i] + i > new_range)
        {
            new_range = arr[i] + i;
            sec_range = 0;
        }
        if (arr[i] + i > sec_range && arr[i] + i < new_range)
            sec_range = arr[i] + i;
        if (i == range || i == n - 1)
        {
            jump++;
            range = new_range;
            new_range = 0;
            if (range < n && arr[range] == 0)
                return -1;
        }
        i++;
    }
    return jump;
}

int greedyMethod(int arr[], int n)
{
    if (n == 0 || n == 1)
        return 0;
    if (arr[0] == 0)
        return -1;

    int maxreach = arr[0];
    int steps = arr[0];
    int jumps = 0;

    forr(i, 1, n){
        if(steps + i >= n-1)
            break;
        steps--;
        maxreach = max(maxreach, arr[i] + i);
        if (steps == 0){
            jumps++;
            steps = maxreach - i;
        }
    }
    return jumps + 1;
}

int main()
{
    forr(i, 0, N)
        dp[i] = 10000;

    int arr[] = {1, 3, 5, 1, 2, 2, 6, 7, 6, 8, 9};
    int n = arrSize(arr);

    cout << Minjump(arr, n) << endl;
    
    forr(i, 1, n + 1)
        cout<< dp[i] << " ";
    cout << endl;

    cout << min_jump(arr, n) << endl;
    cout << greedyMethod(arr, n) << endl;
    return 0;
}
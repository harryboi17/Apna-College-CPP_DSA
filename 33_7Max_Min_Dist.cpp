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

int maxDiff(int arr[], int n)
{
    int A[n / 2], B[n / 2];
    sort(arr, arr + n, greater<int>());

    forr(i, 0, n / 2)
        A[i] = arr[i];
    forr(i, n / 2, n)
        B[n - 1 - i] = arr[i];

    int maxD = 0;
    forr(i,0,n/2)
        maxD += abs(A[i] - B[i]);
    
    return maxD;
}

int minDiff(int arr[], int n){
    int A[n / 2], B[n / 2];
    sort(arr, arr + n, greater<int>());

    for (int i = 0; i < n; i = i+2)
        A[i/2] = arr[i];
    for (int i = 1; i < n; i = i+2)
        B[(i-1)/2] = arr[i];

    int minD = 0;
    forr(i,0,n/2)
        minD += abs(A[i] - B[i]);
    
    return minD;
}

int main()
{
    int arr[] = {7, 8, 12, -6, -2, 2, 5, 4};
    int n = arrSize(arr);

    cout<<"Max Diff : "<<maxDiff(arr,n)<<endl;
    cout<<"Min Diff : "<<minDiff(arr,n)<<endl;
    return 0;
}
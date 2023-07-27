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

//********Dynamic Programming With Memorization Tech**********
int fib(int arr[], int n){
    if(n == 0 || n == 1)
        return 1;

    if(arr[n] != -1)
        return arr[n];
    
    arr[n] = fib(arr, n-1) + fib(arr, n-2);
    return arr[n];
}

int main(){
int fibArr[200];
forr(i,0,200)
    fibArr[i] = -1;

forr(i,0,40)
    cout<<fib(fibArr, i)<<" ";
return 0;
}


//*****************With Tabulation************
/*
int main(){
    int n; cin>>n;

    int fib[n];
    fib[0] = 1; fib[1] = 1;
    cout<<fib[0]<<" "<<fib[1]<<" ";

    forr(i,2,n){
        fib[i] = fib[i-1] + fib[i-2];
        cout<<fib[i]<<" ";
    }

    return 0;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
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

int main(){
int arr[] = {-5, -1, 5, -3, -1, 2, 3, -6};
int n = arrSize(arr);

int maxTillNow = INT_MIN, curr = 0;
forr(i,0,n){
    curr += arr[i];
    maxTillNow = max(maxTillNow, curr);
    if(curr < 0)
        curr = 0;
}
cout<<maxTillNow<<endl;
return 0;
}
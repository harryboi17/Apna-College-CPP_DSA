#include <iostream>
#include <vector>
#include <limits.h>
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
/*
8
3 5 6 9 1 2 7 8
*/
vi bit;
int getSum(int idx){
    int sum = 0;
    while(idx > 0){
        sum += bit[idx];
        idx -= idx & (-idx);
    }
    return sum; 
}

void update(int n, int idx, int inc){
    while(idx <= n){
        bit[idx] += inc;
        idx += idx & (-idx);
    }
}

int main(){
int n; cin>>n;
vi a(n);
for(auto &i : a)
    cin>>i;

vi temp = a;
sort(temp.begin(), temp.end());
forr(i,0,n)
    a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1; //lets say the array is -3 2 0 then this convert it into 1 3 2 
                                                                           //i.e. it gives it the positioning of the number if arranged in sorted order
bit = vi(n+1);                                                             // since count inversion dont care about number, it only care about order

int inv = 0;
for (int i = n-1; i >= 0; i--)
{
    inv += getSum(a[i]);
    update(n, a[i], 1);
}
cout<<inv<<endl;
return 0;
}
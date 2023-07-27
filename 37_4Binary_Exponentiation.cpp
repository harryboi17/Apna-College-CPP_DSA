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
// #define int long long
using namespace std;
const int MOD = 1e9+7;
/*
(a+b)%m = a%m + b%m (in mod m) i.e mod of the answer after the expantion
(a-b)%m = a%m - b%m if ans is negetive add m to the answer
(a*b)%m = a%m * b%m
(a/b)%m = a%m * b^-1 % m

Note : if we take exponential of a very big number, it may get out of range of int or even long long.
       thus calculting MOD of that number will not be possible. thus we have to make a different func
       that will calculate the mod of that number in bit and then add it up to give answer

a^n % MOD ->
convert n into binary say 100101
now if a bit exists we will add it to answer as ans*a and take its MOD
use a = a*a to move to next bit
a^n % MOD = (a^2^m * bit) % MOD + (a^2^m-1 * bit) % MOD +......(a^2^0 * bit) % MOD
*/

int power(int a, int n){
    a %= MOD;  //if a is out of int range 
    int ans = 1;
    while(n>0){
        if(n&1)
            ans = (ans*a) % MOD;
        a = (a*a) % MOD;
        n = n>>1;
    }
    return ans;
}

int Power(int a, int n){ //Recursion
    if(n == 0)
        return 1;
    
    int p = (Power(a,n/2)) % MOD;
    if(n&1)
        return (((p*p)%MOD)*a)%MOD;
    else
        return (p*p)%MOD;
}

signed main(){
int a, n;
cin>>a>>n;
cout<<power(a,n)<<endl;
cout<<Power(a,n)<<endl;
return 0;
}
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
const int MOD = 1e9+7;
/*
*********************FERMATS LITTLE THEORUM*****************
it states that for any number a^p if p is PRIME
then a^p - a is an integral multiple of p
so a^p mod p is = aor
a^p - a whole MOD p is = 0

now if a is not divisible by p then a^p-1 mod p = 1

Multiplying both sides by a^-1
a^p-2 = a^-1(mod p)
i.e a^p-2 is the modulo inverse of A under mod p 

USES:
1) (a/b) % MOD  = (a%m * modInverse(b))%MOD
2) nCr % MOD = (fac(n)%MOD * ModInv(fac(n-r) * ModInv(fac(r))) % MOD (NOTE : we cant use this if p<n as MOD of n with p will then be 0 which is wrong)

********************WILSON'S THEORUM*********************
a Positive interger n>1 is Prime if ans only if
n-1! = -1(Mod n)
or
n-1! = n-1(MOD n)
Example:
101 is a prime implies that 
100! = 101k - 1(mod 101) for some const k

USE:
to Calculate 25! MOD 29
we know 28! is -1
so ans = (-1 * inv(28,29) * inverse(27, 29) * inv(26, 29)) % MOD
*/

/*
QUE : BORING factorial
Given n and p we need to find n! MOD p (p = PRIME)
NOTE : cant find n! as it is too big but given ABS(n-p) <= 1000
if n>p ans = 0 as n will contain p in it thus we will be solving for n<p
*/

int power(int a, int pow, int mod){
    int res = 1;
    a = a%mod;
    while(pow > 0){
        if(pow&1)
            res = (res*a)%mod;
        a = (a*a)%mod;
        pow = pow>>1;
    }
    return res;
}

int ModInv(int n, int p){
    return power(n,p-2,p);
}

int modFact(int n, int p){
    if(p<=n)
        return 0;
    int res = p-1;
    forr(i, n+1, p){
        res = (res*ModInv(i,p))%p;
    }
    return res;
}

int main(){
int n, p;
cin>>n>>p;
cout<<modFact(n,p)<<endl;
return 0;
}
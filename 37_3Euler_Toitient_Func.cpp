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
/*
PROOF:
find No. of numbers from 1 -> n-1 that are coprime with n

f(n) = n*(1 - 1/p1)*(1 - 1/p2)*(1 - 1/p3)...(1 - 1/pk)
where p1 p2 p3 are the distinct Prime factors of the number n
n  = p1^a * p2^b * p3^c....pk^k;

Property : f(A*B) = f(A)*f(B) (if A and B are coPrime)
f(n) = f(p1^a) * f(p2^b) * f(p3^c)....f(pk^k))

No of Numbers that are not CoPrime with p1^a from 1 -> p1^a are
p, 2p, 3p...p^a
to count the numbers this is an AP formula with let say x terms, 1st term as p and common difference as p
p^a = p + (x-1)d
x = p^(a-1);

therefore number of CoPrime of p^a -> p^a - x = p^a - p^(a-1);
f(p^a) = p^a(1 - 1/p)

substituting this result we get:
f(n) = n*(1 - 1/p1)*(1 - 1/p2)*(1 - 1/p3)...(1 - 1/pk)
*/

const int N = 1e5 + 7;
int totient[N];

int main(){
forr(i,0,N)
    totient[i] = i;

forr(i,2,N){
    if(totient[i] == i){ //that means the number is prime and thus we will multiply all of its multiples by i-1/i (1 - 1/i)
        for (int j = 2*i; j < N; j += i) //traversing in multiples
        {
            totient[j] *= i-1; // multiplying (1 - 1/i) as of 1- 1/p from formula
            totient[j] /= i;
        }
        totient[i] = i-1; //if the number is Prime then it is coPrime with all numbers before it. so n-1 numbers
    }
}

forr(i,2,11)
    cout<<totient[i]<<" ";
return 0;
}
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
(A*B) % m = 1 find B

A*B = 1 (mod m)
A*B - 1 = 0 (mod m)
A*B - 1  = mq
A*B + mQ = 1 (can be compared to extended Euclid algo where 1 is the GCD of A,m and we have to find B which is X of the GCD)
*/
struct triplet{
    int x, y, gcd;
};

triplet Extended_Euclid(int a, int b){
    if(b == 0){
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    if(a == 0){
        triplet ans;
        ans.y = 1;
        ans.x = 0;
        ans.gcd = b;
        return ans;
    }

    triplet smallAns = Extended_Euclid(b, a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}

int multiplicative_Modulo_Inverse(int a, int m){ 
    triplet temp = Extended_Euclid(a,m);
    return temp.x;
} 

int main(){
int a, m;
cin>>a>>m;

cout<<multiplicative_Modulo_Inverse(a,m)<<endl;

return 0;
}
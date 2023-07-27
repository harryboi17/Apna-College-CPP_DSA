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
ax + by = gcd(a,b)
gcd(a,b) = gcd(b, a%b)
gcd(b, a%b) = bx1 + (a%b)y1
a%b = a - (a/b)*b

ax + by = bx1 + (a%b)y1;
ax + by = bx1 + (a - (a/b)*b)y1
ax + by = ay1 + b(x1 - (a/b)*y1)

x = y1;
y = x1 - (a/b)*y1;
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

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){
int a, b;
cin>>a>>b;

triplet ans = Extended_Euclid(a,b);
cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<endl;

return 0;
}
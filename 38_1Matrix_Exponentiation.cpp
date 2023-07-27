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
f(n)    =  a b  * f(n-1)
f(n-1)     c d    f(n-2)

to find a b c d, we peformed matrix multiplication and found a = 1 b = 1 c = 1 d = 0
f(n)    =  1 1  * f(n-1)
f(n-1)     1 0    f(n-2)

doing this recursively
f(n)    =  1 1  * 1 1 * 1 1 *... f(2) with n-2 terms of 1 1
f(n-1)     1 0    1 0   1 0      f(1)                   1 0

f(n)    =  (1 1)^n-2 * f(2)
f(n-1)     (1 0)       f(1) 
*/

vector<vi> multiply(vector<vi> &m1, vector<vi> &m2){
    if(m1[0].size() != m2.size()){
        cout<<"cant multiply"<<endl;
        vector<vi> ret(0);
        return ret;
    }

    vector<vi> ans(m1.size(), vi(m2[0].size(), 0));

    forr(i,0,m1.size()){
        forr(j,0,m2[0].size()){
            forr(k,0,m2.size()){
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return ans;
}

vector<vi> matrixExp(vector<vi> &a, int n){
    if(n == 0){
        int sz = a.size();
        vector<vi> ans(sz, vi(sz,0));
        forr(i,0,sz)
            ans[i][i] = 1;
        return ans;
    }

    if(n == 1)
        return a;
    
    vector<vi> temp = matrixExp(a, n/2);
    vector<vi> ans = multiply(temp, temp);

    if(n&1)
        ans = multiply(ans, a);
    return ans;
}   

int main(){
int n; cin>>n;
vector<vi> a = {{1,1}, {1,0}};
vector<vi> ans = matrixExp(a,n);
forr(i,0,ans.size()){
    forr(j,0,ans.size())
        cout<<ans[i][j]<<" ";
    cout<<endl;
}

return 0;
}
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
const int N =1e3;
int dp[N];

int CountBinary(int n){
    if(n == 1 || n == 2)
        return dp[n] = n+1;
    if(dp[n] != -1)
        return dp[n];
    return dp[n] = CountBinary(n-1) + CountBinary(n-2);
}

void PrintBinary(string s, int i, int n){
    if(i == n){
        cout<<s<<endl;
        return;
    }

    PrintBinary(s+"0", i+1, n);
    if(s.size() && s[s.size() -1] == '0'){
        PrintBinary(s+"1", i+1, n);
    }
    else if(s.size() && s[s.size() - 1] == '1'){
    }
    else{
        PrintBinary(s+"1", i+1, n);
    }
}

int main(){
forr(i,1,N)
    dp[i] = -1;
int n; cin>>n;
cout<<CountBinary(n)<<endl;
PrintBinary("",0,n);

return 0;
}
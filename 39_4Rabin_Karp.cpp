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
int p = 31;
const int N = 1e5+2, Mod = 1e9+7;
vector<long long> powers(N);

int main(){
powers[0] = 1;
forr(i,1,N)
    powers[i] = (powers[i-1]*p) % Mod;

string s = "na";
string t = "apnaacollegena";
int T = t.size(), S = s.size();

vector<long long> hash(T+1, 0);
forr(i,0,T){
    hash[i+1] = (hash[i] + ((t[i] - 'a' + 1)*powers[i]))%Mod;
}

long long h_s = 0;
forr(i,0,S)
    h_s = (h_s + ((s[i] - 'a' + 1)*powers[i])) % Mod;

forr(i,0,T-S+1){
    long long cur_hash = (hash[i+S] - hash[i] + Mod) % Mod;
    if(cur_hash == (h_s * powers[i])%Mod)
        cout<<"Found at index "<<i<<endl;
}
return 0;
}
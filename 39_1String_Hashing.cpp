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
const int N = 1e5+2, MOD = 1e9 + 7;
vector<long long> powers(N);

long long calculate_hash(string s){
    long long hash = 0;
    forr(i,0,s.size())
        hash = (hash + ((s[i] - 'a' + 1)*powers[i])) % MOD;
    return hash;
}

int main(){
powers[0] = 1;
forr(i,1,N)
    powers[i] = (powers[i-1]*p) % MOD;

vector<string> strings = {"aa", "ab", "aa", "b", "cc", "ab"};
vector<long long> hashes;
for(auto w : strings)
    hashes.push_back(calculate_hash(w)); //O(nm) m = string size
sort(hashes.begin(), hashes.end()); //nlogn

int distinct = 0;
forr(i,0,hashes.size())
    if(i == 0 || hashes[i] != hashes[i-1])
        distinct++;

cout<<distinct<<endl;

return 0;
}
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

int main(){
string s = "na";
string t = "apna collegena";

int S = s.size(); int T = t.size();
forr(i,0,T-S+1)
    if(t.substr(i,S) == s)
        cout<<"Found at index "<<i<<endl;


return 0;
}
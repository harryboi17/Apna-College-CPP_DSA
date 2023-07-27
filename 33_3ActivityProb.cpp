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
vector<pii> v;
int n ; cin>>n;

forr(i,0,n){
    int s, e;
    cin>>s>>e;
    v.pb({s,e});
}

sort(v.begin(), v.end(), [&](pii &a, pii &b){
    return a.ss < b.ss;
});

int take = 1;
int end = v[0].ss;

vector<pii> ans;
ans.push_back({v[0].ff, v[0].ss});

forr(i,1,n){
    if(v[i].ff > end){
        take++;
        end = v[i].ss;
        ans.pb({v[i].ff, v[i].ss});
    }
}

for(auto i : ans)
    cout<<i.ff<<" "<<i.ss<<"  ";
cout<<endl<<take<<endl;
return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
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
int arr[] = {1,2,2,2,3,1};
int n = arrSize(arr);

int k; cin>>k;
map<int, int> m;

forr(i,0,n){
    int curSize = m.size();
    if(m[arr[i]] == 0 && curSize == k)
        break;
    m[arr[i]]++;
}

vector<pii> ans;
for(auto i : m)
    if(i.ss != 0)
        ans.pb({i.ss, i.ff});

sort(ans.begin(), ans.end(), greater<pii>());

for(auto i : ans)
    cout<<i.ss<<" "<<i.ff<<endl;
return 0;
}
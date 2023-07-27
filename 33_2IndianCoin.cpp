#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
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
int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int n = arrSize(arr);
sort(arr, arr+n);

int k; cin>>k;
int sum = 0, count = 0;
map<int, int, greater<int>> m;
/*
for (int i = n-1; i >= 0; i--)
{
    while (sum < k)
    {
        sum += arr[i];
        m[arr[i]]++;
    }
    if(sum == k)
        break;
    sum -= arr[i];
    m[arr[i]]--;
}
*/

for(int i = n-1; i >= 0; i--){
    count += k/arr[i];
    m[arr[i]] = k/arr[i];
    k -= k/arr[i] * arr[i];
}

for(auto i : m)
    if(i.ss != 0)
        cout<<"Coin Value : "<<i.first<<"  total coins : "<<i.ss<<endl;

cout<<"Count : "<<count;
return 0;
}
#include <iostream>
#include <map>
#include <vector>
#define forr(i,s,e) for(int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

int main(){
int arr[] = {};
int n = sizeof(arr)/sizeof(arr[0]);

int Presum = 0;
map<int, int> m;
forr(i,0,n){
    Presum += arr[i];
    m[Presum]++;
}

int count = 0;
for(auto i : m){
    if(i.first == 0)
        count += i.second;
    count += (i.second)*(i.second - 1)/2;
}

cout<<count;
return 0;
}
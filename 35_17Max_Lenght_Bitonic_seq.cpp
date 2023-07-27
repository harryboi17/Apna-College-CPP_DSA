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
int arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
int n = arrSize(arr);

vi forward(n, 1), backward(n, 1);
forr(i,0,n)
    forr(j,i,n)
        if(arr[i] > arr[j])
            forward[i] = max(forward[i], 1 + forward[j]);

for(int i = n-1; i >= 0; i--)
    for(int j = n-1; j > i; j--)
        if(arr[i] > arr[j])
            backward[i] = max(backward[i], 1 + backward[j]);

int ans = 0;
forr(i,0,n)
    ans = max(ans, forward[i] + backward[i] - 1);
cout<<ans<<endl;

return 0;
}
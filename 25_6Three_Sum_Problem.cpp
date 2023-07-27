#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
int n; cin>>n;
int target; cin>>target;
vector<int> arr(n);
for(auto &i : arr){
    cin>>i;
}

sort(arr.begin(), arr.end()); //O(nlog(n))

bool found = false;
for (int i = 0; i < n; i++) //O(n^2)
{
    int lo = i+1; int hi = n-1;
    while (lo<hi)
    {
        int cur = arr[i] + arr[lo] + arr[hi];
        if (cur == target)
        {
            found = true;
            cout<<"FOUND!"<<endl;
            cout<<arr[i]<<" "<<arr[lo]<<" "<<arr[hi]<<endl;
            break;
        }
        else if(cur < target){
            lo++;
        }
        else{
            hi--;
        }
    }   
}   

if (!found)
{
    cout<<"NOT FOUND!"<<endl;
}

return 0;
}
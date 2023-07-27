#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> v;

    int k; cin>>k;
    int maxsum; cin>>maxsum;

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if(sum < maxsum) v.push_back(sum);

    for (int i = k; i < n; i++)
    {
        sum = sum - arr[i-k] + arr[i];
        if(sum < maxsum) v.push_back(sum);
    }
    
    for(auto i:v){
        cout<<i<<" ";
    }
    return 0;
}
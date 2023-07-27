#include <iostream>
#include <algorithm>
using namespace std;

bool IsFeasible(int mid, int arr[], int n, int k){
    int pos = arr[0], elements = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largestMinDist(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int s = 1, e = arr[n - 1]; // this is range of distance 
    while (s < e)
    {
        int mid = (s + e) / 2;
        if(IsFeasible(mid, arr, n, k)){
            result = max(result, mid);
            s = mid+1;
        }else{
            e = mid;
        }
    }
    return result ;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k; cin>>k;
    cout<<"The Largest Min Distance is: "<<largestMinDist(arr, n, k);

    return 0;
}
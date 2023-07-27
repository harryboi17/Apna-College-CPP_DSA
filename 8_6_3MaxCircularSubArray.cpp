#include <iostream>
using namespace std;
/*
here in circular loop the last element of array can be part of subarray which also include first element
example: [4, -4, 6, -6, 10, -11, 12] here a subarray [12, 4] exists.
to find max sum, we will use formula:
Max subarray sum = total sum of array - max sum of Non conrtributing elements.
Here, -11 is the only non contributing element.
*/

int kedane(int arr[],int n)
{
    int cursum = 0;
    int maxi = -1000000;
    for (int i = 0; i < n; i++)
    {
        cursum += arr[i];
        if (cursum < 0)
        {
            cursum = 0;
        }
        maxi = max(maxi, cursum); 
    }
    return maxi;
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
    
    int nonwrapsum = kedane(arr, n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        arr[i] = arr[i] * (-1);
    }
    int wrapsum = sum + kedane(arr,n);//here we used + because we have to subtract the negetive part of kedane

    cout << max(nonwrapsum, wrapsum)<<endl;
    return 0;
}
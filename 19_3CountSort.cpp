#include <iostream>
#include <algorithm>
using namespace std;
// TIME COMPLEXITY : O(max (sizeofarr, max element of arr) )
int countsort(int arr[], int n)
{
    int maxi = arr[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int countarr[maxi + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        countarr[arr[i]]++;
    }

    for (int i = 1; i < maxi+1; i++)
    {
        countarr[i] += countarr[i - 1]; //this helps to give indexing of array at that position
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[--countarr[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n] = {1, 3, 2, 3, 4, 1, 6, 4, 3};

    countsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    /*
*******BAD TIME COMPLEXITY IF ARRAY MAX ELEMENT IS REALLY BIG ELSE = O(n)*****
for (int i = 0; i < maxi+1; i++)
{
 for (int j = 0; j < countarr[i]; j++)
 {
     cout<<i<<" ";
 }    
}
*/

    return 0;
}
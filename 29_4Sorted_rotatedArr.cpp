#include <iostream>
using namespace std;

int rotatedArr(int arr[], int key, int start, int end)
{
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[start] < arr[mid])
    {
        if (key >= arr[start] && key <= arr[mid])
        {
            return rotatedArr(arr, key, start, mid-1);
        }
        return rotatedArr(arr, key, mid+1, end);
    }
    
    if (arr[mid] <= key && arr[end] >= key)
    {
        return rotatedArr(arr, key, mid+1, end);
    }
    return rotatedArr(arr, key, start, mid-1);
    
}

int main()
{
    cout<<"Enter the size of array: ";
    int n; cin>>n;
    int arr[n];
    cout<<"Enter the value of elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value of key to search : ";
    int key; cin>>key;
    
    cout<<"The key is present at the INDEX : ";
    cout<<rotatedArr(arr, key, 0, n-1)<<endl;
    return 0;
}
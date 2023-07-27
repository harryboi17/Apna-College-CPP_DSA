#include <iostream>
using namespace std;

int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int x; cin>>x;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    int s = 0, e = n-1, size = n+1;
    while (sum > x)
    {
        if (arr[s] < arr[e])
            sum -= arr[s++];
        else
            sum -= arr[e--];
            
        size--;
    }

    if(size == n+1){
        cout<<"Min SubArray doesn't exist"<<endl;
    }else{
        cout<<"Min SubArray size is : "<<size<<endl;
    }

    return 0;
}
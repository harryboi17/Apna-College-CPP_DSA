#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

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
    cout<<maxi<<endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "Enter the size of array" << endl;
    int n;
    cin >> n;

    int arr[n];
    cout << "Enter the Elements of Array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the number whom you want to be equal to the sum of a subarray" << endl;
    int S;
    cin >> S;

    int sum = 0;
    int i = 0;
    while (S > sum)
    {
        sum += arr[i];
        i++;
    }
    i = i - 1;

    int j = 0;
    while (S < sum)
    {
        sum = sum - arr[j];
        j++;
    }
    if (sum == S)
    {
        cout << j << " " << i;
    }
    else
    {
        cout << "No such subarray exists which have the sum equal to the given number";
    }
    
    return 0;
}
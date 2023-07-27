#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n"<<endl;
    cin >> n;
    int arr[n];
    cout<<"Enter the value of arrays"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    const int N = 1e5+2;
    int index[N];
    for (int i = 0; i < N; i++)
    {
        index[i] = -1;
    }

    int mindex = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (index[arr[i]] != -1)
        {
            mindex = min(mindex, index[arr[i]]);
        }
        else
        {
            index[arr[i]] = i;
        }
    }

    if (mindex == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << mindex + 1 << endl;
    }

    return 0;
}
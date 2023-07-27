#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
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

    int store[(n * (n + 1)) / 2][n];
    int b = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int a = 0;
            for (int k = i; k <= j; k++)
            {
                store[b][a] = arr[k];
                a++;
            }
            b++;
        }
    }

    //******COUT THE STORE ARRAY*******
    /*
    int c = 0;
    int d = 0;
    for (int i = 0; i < (n * (n + 1)) / 2; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            cout << store[i][j] << " ";
        }  
        c++;
        if(c == n-d){
            c = 0;
            d++;
        }
        cout << endl;
    }
    */

    int c = 0;
    int d = 0;
    int arr1[(n * (n + 1)) / 2];
    for (int i = 0; i < (n * (n + 1)) / 2; i++)
    {
        int sum = 0;
        for (int j = 0; j <= c; j++)
        {
            sum += store[i][j];
        }
        arr1[i] = sum;
        c++;
        if (c == n - d)
        {
            c = 0;
            d++;
        }
    }

    /*for (int i = 0; i < (n * (n + 1)) / 2; i++)
    {
        cout<<arr1[i]<<" ";
    }*/

    int maxi = -100000;
    for (int i = 0; i < (n * (n + 1)) / 2; i++)
    {
        maxi = max(maxi,  arr1[i]);
    }
    cout<<maxi<<endl;
    return 0;
}
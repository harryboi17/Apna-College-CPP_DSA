#include <iostream>
using namespace std;

bool pairsum(int arr[], int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        if (arr[low] + arr[high] == k)
        {
            cout << low << " " << high << endl;
            return true;
        }
        else if (arr[low] + arr[high] > k)
        {
            high--;
        }
        else
        {
            low++;
        }
        return false;
    }
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

    int k;
    cin >> k;
    /*
    bool check = false;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << "Yes, 2 such elements exists whose sum is equal to the given number" << endl;
                cout << "Thier index is: " << i << " " << j << endl;
                check = true;
                break;
            }
        }
    }
    if (check == false)
    {
        cout << "NO 2 such elements exists whose sum is equal to the given number";
    }
    */
    cout << pairsum(arr, n, k) << endl;
    return 0;
}
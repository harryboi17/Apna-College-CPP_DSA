#include <iostream>
using namespace std;

void checkPallindrom(int arr[], int n, int k)
{
    for (int i = 0; i < n - k + 1; i++)
    {
        bool check = true;
        for (int j = i; j < k / 2 + i; j++)
        {
            if (arr[j] != arr[j + k - 1])
            {
                check = false;
                continue;
            }
        }
        if (check)
        {
            for (int j = i; j < i + k; j++)
            {
                cout << arr[j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int arr[] = {2, 3, 2, 3, 5, 7, 6 ,7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k;
    cin >> k;
    checkPallindrom(arr, n, k);

    return 0;
}
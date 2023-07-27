#include <iostream>
#include <cmath>
using namespace std;

bool isPerfect(int n)
{
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++)
        if (n % i == 0)
            sum += i + n / i;

    if (sum == n)
        return true;
    return false;
}

void PerfectNum(int arr[], int n, int k)
{
    int perfect = 0;
    int ans = 0;
    for (int i = 0; i < k; i++)
        if (isPerfect(arr[i]))
            perfect++;
            
    ans = max(ans, perfect);

    for (int i = k; i < n; i++)
    {
        if (isPerfect(arr[i]))
            perfect++;

        if (isPerfect(arr[i - k]))
            perfect--;

        ans = max(ans, perfect);
    }
    cout << ans;
}

int main()
{
    int arr[] = {28, 2, 3, 6, 496, 99, 8128, 24};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k; cin>>k;

    PerfectNum(arr, n, k);
    return 0;
}
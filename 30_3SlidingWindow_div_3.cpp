#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int CalcDigits(int n)
{
    int digit = 0;
    while (n > 0)
    {
        n = n / 10;
        digit++;
    }
    return digit;
}

void divby3(int arr[], int n, int k)
{
    vector<pair<int, int>> ans;
    int sum = 0;

    for (int i = 0; i < k; i++)
        sum += arr[i];

    if (sum % 3 == 0)
        ans.push_back(make_pair(0, k - 1));

    for (int i = k; i < n; i++)
    {
        sum = sum + arr[i] - arr[i - k];

        if (sum % 3 == 0)
        {
            ans.push_back(make_pair(i - k + 1, i));
        }
    }

    for (auto i : ans)
    {
        for (int j = i.first; j <= i.second; j++)
        {
            cout << arr[j];
        }
        cout << " ";
    }
}

void myMethod(int arr[], int n, int k)
{
    vector<int> v;
    float sum = 0;

    for (int i = 0; i < k; i++)
    {
        int dig = CalcDigits(arr[i]);
        sum = sum * (pow(10, dig)) + arr[i];
    }
    if (int(sum) % 3 == 0)
        v.push_back(sum);

    for (int i = k; i < n; i++)
    {

        int sumdig = CalcDigits(sum);
        int dig = CalcDigits(arr[i - k]);
        float power = pow(10, sumdig - dig);
        sum = int(sum) % int(power);

        dig = CalcDigits(arr[i]);
        sum = sum * (pow(10, dig)) + arr[i];

        if (int(sum) % 3 == 0)
            v.push_back(sum);

    }

    for (auto i : v)
        cout << i << " ";

}

int main()
{

    int arr[] = {4, 23, 45, 12, 56, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int k;
    cin >> k;

    divby3(arr, n, k); cout << endl;
    myMethod(arr, n, k); cout<<endl;

    return 0;
}
#include <iostream>
#include <climits>
using namespace std;

bool IsPossible(int arr[], int n, int m, int min){
    int studentsreq = 1, sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
            return false;

        if (sum+arr[i] > min)
        {
            studentsreq++;
            sum = arr[i];
            if (studentsreq > m)
                return false;
        }
        else
            sum += arr[i];         
    }
    return true;
}

int PageAllocation(int arr[], int n, int m)
{
    int sum = 0;
    if (n < m)
        return -1;

    for (int i = 0; i < n; i++)
        sum = sum + arr[i]; 

    int start = 0, end = sum, ans = INT_MAX;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (IsPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return ans;
}

int main()
{
    int arr[] = {90, 12, 34, 40};
    cout<<PageAllocation(arr, 4, 2);
    return 0;
}
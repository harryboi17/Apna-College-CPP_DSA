#include <iostream>
using namespace std;

int tile(int n)
{
    if (n == 2)
    {
        return 2;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n < 1)
    {
        return 0;
    }

    return tile(n - 1) + tile(n - 2);
}

int pairing(int n)
{
    if (n == 0 || n == 1 || n == 2)
    {
        return n;
    }

    return pairing(n - 1) + (pairing(n - 2) * (n - 1));
}

int knapsack(int value[], int wt[], int n, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n - 1] > W)
    {
        return knapsack(value, wt, n - 1, W); 
    }

    return max(knapsack(value, wt, n - 1, W - wt[n - 1]) + value[n - 1], knapsack(value, wt, n - 1, W));
}

int main()
{
    // cout<<tile(7)<<endl;
    // cout<<pairing(5)<<endl;
    int wt[] = {7, 4, 6, 5, 6};
    int n = sizeof(wt)/sizeof(wt[0]);
    int value[] = {21, 24, 12, 40, 30};
    int W = 20;
    cout << knapsack(value, wt, n, W) << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <limits.h>
#define forr(i, s, e) for (int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr) / sizeof(arr[0])
using namespace std;

void expedi(int TownDis, int fuel, vector<pii> stopfuel, int n, int stops, int &ans, int i) //Brute force O(2^n);
{
    if (fuel >= TownDis)
    {
        ans = min(stops, ans);
        return;
    }

    while (fuel >= stopfuel[i].ff && i < n)
    {
        expedi(TownDis - stopfuel[i].ff, fuel + stopfuel[i].ss - stopfuel[i].ff, stopfuel, n, stops + 1, ans, i + 1);
        i++;
    }
}

int betterMethod(int TownDis, int fuel, vector<pii> stopfuel, int stopCount) //Greedy Method O(nlog(n));
{
    priority_queue<int, vi> pqfuel;
    int i = 0;

    while (fuel < TownDis)
    {
        if (fuel >= stopfuel[i].ff)
        {
            fuel -= stopfuel[i].ff;
            TownDis -= stopfuel[i].ff;
            pqfuel.push(stopfuel[i].ss);
            i++;
        }
        else
        {
            stopCount++;
            fuel += pqfuel.top();
            pqfuel.pop();
        }
    }
    return stopCount;
}
int main()
{
    int TownDis, fuel;
    cin >> TownDis >> fuel;

    int stop[] = {4, 5, 11, 15}; //from town;
    int fuelatStop[] = {4, 2, 5, 10};
    int n = arrSize(stop);

    vector<pii> stopfuel;

    int DistBus[n]; // 10, 14, 20, 21
                    // 10,  5,  2,  4
    forr(i, 0, n)
    {
        DistBus[i] = TownDis - stop[i];
        stopfuel.pb({DistBus[i], fuelatStop[i]});
    }

    int stopCount = 0;
    sort(stopfuel.begin(), stopfuel.end());

    for (int i = n - 1; i >= 1; i--)
        stopfuel[i].ff -= stopfuel[i - 1].ff;

    /*
    int ans = INT_MAX;
    expedi(TownDis, fuel, stopfuel, n, 0, ans, 0);
    cout << ans;
    */

   cout<<betterMethod(TownDis, fuel, stopfuel, 0)<<endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define forr(i, s, e) for (int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr) / sizeof(arr[0])
using namespace std;

const int INF = 1e9;

int main()
{
    vector<vi> graph = {
                            {0, 5, INF, 10},
                            {INF, 0, 3, INF},
                            {INF, INF, 0, 1},
                            {INF, INF, INF, 0}
                       };
    int n = graph.size();

    vector<vi> dist = graph;
    forr(k, 0, n)
        forr(i, 0, n)
            forr(j, 0, n) 
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    return 0;
}
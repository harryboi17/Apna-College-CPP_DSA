#include <iostream>
using namespace std;
/*
5
1 0 1 0 1
1 1 1 0 0
1 0 1 1 1
1 1 0 0 1
0 0 0 0 1
*/
bool rat(int *p[], int n, int i, int j)
{
    if (i > n - 1 || j > n - 1)
        return false;
    if (p[i][j] == 0)
        return false;

    if (i == n - 1 && j == n - 1)
    {
        cout << i << " " << j << endl;
        return true;
    }
    if ((rat(p, n, i, j + 1) || rat(p, n, i + 1, j)))
        cout << i << " " << j << endl;
}

//*****************METHOD 2****************

bool IsSafe(int *arr[], int x, int y, int n)
{
    if(x < n && y < n && arr[x][y] == 1)
        return true;
    return false;
}

bool ratInMaze(int *arr[], int x, int y, int n, int *SolArr[])
{
    if (x == n-1 && y == n-1)
    {
        SolArr[x][y] = 1;
        return true;
    }
    
    if (IsSafe(arr, x, y, n))
    {
        SolArr[x][y] = 1;
        if (ratInMaze(arr, x+1, y, n, SolArr))
            return true;
        if (ratInMaze(arr, x, y+1, n, SolArr))
            return true;
        
        SolArr[x][y] = 0;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int *p[n];
    for (int i = 0; i < n; i++)
        p[i] = new int[n];

    int *SolArr[n];
    for (int i = 0; i < n; i++){
        SolArr[i] = new int[n];
        for (int j = 0; j < n; j++)
            SolArr[i][j] = 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> p[i][j];

    rat(p, n, 0, 0); cout<<endl;
    ratInMaze(p,0,0,n,SolArr);

     for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << SolArr[i][j]<<" ";
        cout<<endl;
     }
    return 0;
}
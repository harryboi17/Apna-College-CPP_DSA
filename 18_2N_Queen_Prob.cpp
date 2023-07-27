#include <iostream>
using namespace std;

bool isSafe(int *p[], int n, int x, int y){
    for (int row = 0; row < x; row++){
       if (p[row][y] == 1)
           return false;
    }

    int row = x;
    int col = y;
    while (row>= 0 &&  col >= 0){
        if (p[row][col] == 1)
            return false;
        row --;
        col --;
    }

    row = x;
    col = y;
    while (row>= 0 && col < n){
        if (p[row][col] == 1)
            return false;
        row --;
        col ++;
    }
    
    return true;
}

bool NQueen(int *p[], int n, int x){
    if (x>=n)
    {
        return true;
    }
    
    for (int col = 0; col < n; col++)
    {
        if (isSafe(p,n,x,col))
        {
            p[x][col] = 1;
            if (NQueen(p,n,x+1))
            {
                return true;
            }
            p[x][col] = 0; 
        }
    }
    return false;
    
}
 
int main()
{
    int n; cin >> n;
    int *p[n];
    for (int i = 0; i < n; i++)
    {
        p[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            p[i][j] = 0;
        }
    }

    if (NQueen(p,n,0))
    {
        for (int i = 0; i < n; i++)
        {
            cout<<endl;
            for (int j = 0; j < n; j++)
            {
                cout<<p[i][j]<<" ";
            } 
        }
        
    }
    
    return 0;
}
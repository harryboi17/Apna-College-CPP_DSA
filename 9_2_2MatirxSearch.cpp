#include <iostream>
using namespace std;

int main()
{
    cout<<"enter the value of row and coloums"<<endl;
    int n, m;
    cin >> n >> m;
    int mat[n][m];

    cout<<"Enter the value of the elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout<<"Enter the value of the target"<<endl;
    int target; cin>>target;

    bool found = false;
    int r = 0; int c = m-1;
    while(r<n && c>= 0){
        if (mat[r][c] == target)
        {
            found  = true;
            cout<<"Target found at index: "<<r+1<<" "<<c+1<<endl;
            break;
        }
        else if(mat[r][c]>target){
            c--;
        }
        else{
            r++;
        }
    }

    if (found == false){
        cout<<"Target not found"<<endl;
    }
    
    return 0;
}
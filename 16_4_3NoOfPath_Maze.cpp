#include <iostream>
using namespace std;

int path(int n, int i, int j){
    if (i == n-1 && j == n-1)
    {
        return 1;
    }
    if (i>=n || j>=n)
    {
        return 0;
    }
    
    return path(n, i+1, j) + path(n, i, j+1);
}

int main(){
cout<<path(4,0,0);

return 0;
}
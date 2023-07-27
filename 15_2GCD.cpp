#include <iostream>
using namespace std;
/*
int GCD(int x, int y)
{
    int temp;
    temp = x % y;
    if (temp != 0)
    {
        GCD(y, temp);
    }
    else{
        return y;
    }
}
*/
int GCD(int x, int y)
{
    while (y != 0)
    {
        int rem  = x%y;
        x = y;
        y = rem;
    }
    return x;   
}

int main()
{
    cout<<GCD(42,24)<<endl;
    return 0;
}
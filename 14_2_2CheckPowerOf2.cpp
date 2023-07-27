#include <iostream>
using namespace std;
/*
int bitCheck(int n)
{
    bool check = 1;
    for (int i = 0; i < 1000; i++)
    {
        if (n == 1 << i)
        {
            cout << "The number is a power of 2" << endl;
            check = 0;
            break;
        }
    }
    if (check)
    {
        cout << "The number is not a power of 2" << endl;
    }
}
*/

int bitCheck(int n){
    return (n && !(n & n-1));
}
/*
note: 8 = 1000, 7= 0111;
on applying & operator we get 0000;
this only happens with numbers who are a power of 2;
we also used n && for special case of 0, cause we cannot find n-1 for 0;
*/
int main()
{
    int n;
    cout << "Enter the number" << endl;
    cin >> n;
    cout<<bitCheck(n)<<endl;
    return 0;
}
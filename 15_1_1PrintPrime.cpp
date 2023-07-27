#include <iostream>
using namespace std;
/*
marking all the numbers which have are a multiple of a previous number
*/
void PrimeSeive(int n){
    int prime[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i*i; j <= n ; j += i)
            {
                prime[j] = 1;
            }   
        }  
        if (i*i > n)
        {
            break;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            cout<<i<<" ";
        }
    }
}

int main(){
PrimeSeive(100);
return 0;
}
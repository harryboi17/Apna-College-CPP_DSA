#include <iostream>
using namespace std;

void PrimeFac(int n){
    int spf[10000];
    for (int i = 0; i <= n; i++)
    {
        spf[i] = i;
    }
    
    for (int i = 2; i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i*i; j <= n; j+=i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
                
            }
            
        }
        
    }
    
    while (n != 1)
    {
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }
    
}

int main(){
    int n;
    cin>>n;
    PrimeFac(n);

return 0;
}
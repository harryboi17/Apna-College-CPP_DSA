#include <iostream>
#include <cmath>
using namespace std;
/*
int unique(int arr[], int n){
    int bitarr[64];
    for (int i = 0; i < 32; i++)
    {
        bitarr[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (1<<i & arr[j])
            {
               bitarr[i]++;
            }      
        }
    }

    int sum = 0 ;
    for (int i = 0; i < 32; i++)
    {
        bitarr[i] = bitarr[i]%3;
        sum += (bitarr[i]*int(pow(2,i)));
    }
    cout<<sum<<endl;
}   
*/

int setBit(int n, int pos){
    return (n | (1<<pos));
}

void unique(int arr[], int n){
    int result =0;
    for (int i = 0; i < 32; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (1<<i & arr[j])
            {
               sum++;
            }      
        }
        if (sum%3 != 0)
        {
            result = setBit(result,i);
        }
    }
    cout<<result<<endl;
}  

int main(){
int arr[10] = {1,2,2,4,4,4,3,1,1,2};
unique(arr, 10);

return 0;
}
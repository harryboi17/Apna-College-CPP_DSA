#include <iostream>
using namespace std;
/*
what is xor(^)?
0^0 = 0, 1^1 = 0, 0^1 = 1, 1^0 = 1
*/

int unique(int arr[], int n){
    int xorsum=  0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i]; // xorsum^arr[i]
    }
    return xorsum;
}

int main(){
int arr[8] = {1,2,3,1,2,3,4,5}; //used to find only one unique number
int n = sizeof(arr)/sizeof(arr[0]);
cout<<unique(arr,n)<<endl;

return 0;
}
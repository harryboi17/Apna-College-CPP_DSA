#include <iostream>
using namespace std;
/*
if their are 2 unique numbers the xorsum function will give out zor of those 2 unique numbers
now to seperate the xors of those numbers we first have to find the where the number 1 is in xorsum
and then check which all numbers have number 1 in binary term at that place and find the zor of them
and you will get your number, now take zor of that number with xorsum u had before and u will get second no.
*/

int setBit(int n , int pos){
    return ((n & (1<<pos)) != 0);
}

void unique(int arr[], int n){
    int xorsum=  0;
    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i]; // xorsum^arr[i]
    }
    int setbit = 0;
    int pos = 0;
    int tempxor = xorsum;
    while (setbit != 1)
    {
        setbit = xorsum & 1; // will give 0 in allk cases except one
        pos++; //to find the position of 1 in xorsum
        xorsum = xorsum >> 1;  //right shifting 0010 to 0001
    }


    int newxor = 0;
    for (int i = 0; i < n; i++)
    {
        if (setBit(arr[i], pos-1))
        {
            newxor = newxor^arr[i];
        }      
    }
    
    cout<<newxor<<" "<<(tempxor^newxor)<<endl;
}

int main(){
int arr[11] ={1, 3, 5, 6, 5, 7, 1, 2, 6, 3,8};
unique(arr, 11);

return 0;
}
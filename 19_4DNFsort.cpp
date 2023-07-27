#include <iostream>
using namespace std;
/*
used to sort 0,1,2 only or say a set of numbers having only 3 distinct elements
Time Comeplxity : O(n)
*/

void DNF(int arr[], int n){

    int low = 0, mid = 0, high = n-1;

    while (mid != high)
    {
        if (arr[mid] == 0)
        {
         swap(arr[low], arr[mid]);
         low++; mid++;   
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
        
    } 
}

int main(){
int arr[] = {1,0,2,1,0,1,2,1,2};

DNF(arr, 9);
for (int i = 0; i < 9; i++)
{
    cout<<arr[i]<<" ";
}


return 0;
}
#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key){
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid  = (s+e)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]>key){
            e = mid -1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

int main(){
int n;
cout<<"Enter the size of array : ";
cin>>n;
int arr[n];
cout<<"Enter the value of array"<<endl;
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
} 
  
int key;
cout<<"Enter the value of KEY to search : ";
cin>>key;
cout<<endl;

cout<<"The Key is at INDEX : "<<BinarySearch(arr, n, key)<<endl;

return 0;
}
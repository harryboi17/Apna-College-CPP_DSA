#include <iostream>
using namespace std;
/*
cout in wave form that is both neighbouring element of alternate array
must be greater than the current element
*/
int main(){
int n; cin>>n;
int arr[] = {1,3,4,7,5,6,2};

for (int i = 1; i < n; i += 2)
{
   if (arr[i] > arr[i-1])
   {
       swap(arr[i], arr[i-1]);
   }
   if (arr[i] > arr[i+1] && i<=n-2)
   {
       swap(arr[i], arr[i+1]);
   }
}

for (int i = 0; i < n; i++)
{
    cout<<arr[i]<<" ";
}

return 0;
}
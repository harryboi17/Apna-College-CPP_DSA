#include <iostream>
using namespace std;

int main(){
cout<<"Enter the size of array"<<endl;
int n;
cin>>n;

int arr[n];
cout<<"Enter the value of Elements of array"<<endl;
for (int i = 0; i < n; i++)
{
    cin>>arr[i];
}

int mini = 100000;
for (int i = 0; i < n; i++)
{
    if(arr[i]>0){
        mini = min(mini, arr[i]);
    }
    else{
        continue;
    }
}
cout<<mini+1;

return 0;
}
#include <iostream>
using namespace std;
//Q : count inversion
// there is a inversion when arr[i] > arr[j] with j > i

int merge(int arr[], int l, int mid, int r){
    int inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1]; int b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l+i];
    for (int i = 0; i < n2; i++)
        b[i] = arr[mid+1+i];

    int i = 0; int j = 0;
    int k = l;

    while (i<n1 && j<n2)
    {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else{
            inv += n1 - i;
            arr[k++] = b[j++];
        }
    }
    while(i<n1)
        arr[k++] = a[i++];
    while(j<n2)
        arr[k++] = b[j++];
    
    return inv;
}

int MergeSort(int arr[], int l, int r){
    int inv = 0;
    if(l<r){
        int mid = (l+r)/2;
        inv += MergeSort(arr, l, mid);
        inv += MergeSort(arr, mid+1, r);

        inv += merge(arr, l, mid, r);
    }
    return inv;
}

int main(){
int arr[] = {5,4,3,2,1};
cout<<"Total inversions are : ";
cout<<MergeSort(arr, 0, 4 )<<endl;
for (int i = 0; i < 5; i++)
    cout<<arr[i]<<" ";

 
return 0;
}
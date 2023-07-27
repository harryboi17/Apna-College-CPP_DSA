#include <iostream>
#include <vector>
#define forr(i,s,e) for(int i = s; i < e; i++)
using namespace std;
/*
heapify : O(log(n));
heapSort : O(nlog(n));
creating max heap or min heap : O(n);
*/
void heapify(vector<int> &v, int n, int i){
    int maxIDX = i;
    int left = 2*i + 1;
    int right  = 2*i + 2;

    if(left < n && v[left] > v[maxIDX])
        maxIDX = left;
    
    if(right < n && v[right] > v[maxIDX])
        maxIDX = right;
    
    if (maxIDX != i)
    {
        swap(v[i], v[maxIDX]);
        heapify(v, n, maxIDX);
    }  
}

void heapsort(vector<int> &v){
    int n = v.size();

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(v, n, i);

    for (int i = n-1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0); 
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    forr(i,0,n)
        cin>>v[i];
    heapsort(v);
    forr(i, 0, n)
        cout<<v[i]<<" ";
   
    return 0;
}
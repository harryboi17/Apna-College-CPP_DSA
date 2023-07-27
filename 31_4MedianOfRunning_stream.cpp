#include <iostream>
#include <queue>
#include <vector>
#define forr(i, s, e) for (int i = s; i < e; i++)
using namespace std;

priority_queue<int, vector<int>, greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int x)
{
    if (pqmax.size() == pqmin.size())
    {
        if (pqmax.size() == 0){
            pqmax.push(x);
            return;}
        
        if (x < pqmax.top())
            pqmax.push(x);
        else
            pqmin.push(x);
    }
    else
    {
        if(pqmax.size() > pqmin.size()){
            if(x >=  pqmax.size())
                pqmin.push(x);
            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else{
            if(x <= pqmin.top())
                pqmax.push(x);
            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian(){
    if (pqmax.size() == pqmin.size())
        return (pqmax.top() + pqmin.top())/2.0;
    else if(pqmax.size() > pqmin.size())
        return pqmax.top();
    else
        return pqmin.top();
}

int main()
{
    int arr[6] = {10 , 15, 21 , 18, 30, 19};
    forr(i,0,6){
        insert(arr[i]);
        cout<<findMedian()<<" ";
    }
    return 0;
}
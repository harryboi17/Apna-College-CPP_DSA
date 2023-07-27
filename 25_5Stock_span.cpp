#include <iostream>
#include <stack>
using namespace std;

int main(){
int arr[] = {100,80,60,70,60,75,85};
int n = sizeof(arr)/sizeof(arr[0]);
int ans[n];
for (int i = 0; i < n; i++)
{
    ans[i] = 1;
}


stack<int> st;
for (int i = 0; i < n; i++)
{
    while(!st.empty() && arr[i] > arr[st.top()])
    {
       ans[i] += ans[st.top()];
       st.pop(); 
    }
    st.push(i);
}

for(auto &i : ans){
    cout<<i<<" ";
}
return 0;
}
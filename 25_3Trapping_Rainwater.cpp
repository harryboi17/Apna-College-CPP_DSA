#include <iostream>
#include <stack>
using namespace std;

int rainwater(int arr[], int n)
{
    int rainwater = 0;
    stack<int> st;
    st.push(0);

    for (int i = 1; i < n; i++)
    {
        while (arr[st.top()] > arr[i])
        {
            st.push(i);
            if (i == n-1)
                break;   
            i++;
        }

        while (!st.empty() && arr[i] > arr[st.top()])
        {
            int l = arr[st.top()];
            st.pop();
            if (st.empty())
                break;
            rainwater += (i-st.top()-1)*(min(arr[st.top()], arr[i]) - l);
        }
        st.push(i);
    }
    return rainwater;
}
/******************BETTER METHOD*************************
int trappingRainwater(vector<int> heights)
{
    int n = heights.size();
    vector<int> left(n);
    vector<int> right(n);
    int ans = 0;

    stack<int> st;
    for (int i = 0; i < n; i++){
        if (st.empty()){
            left[i] = 0;
            st.push(i);
            continue;
        }
        left[i] = heights[st.top()];
        if (!st.empty() && heights[i] > heights[st.top()])
            st.push(i);
    }

    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--){
        if (st.empty()){
            right[i] = 0;
            st.push(i);
            continue;
        }
        right[i] = heights[st.top()];
        if (!st.empty() && heights[i] > heights[st.top()])
            st.push(i);
    }
    
    for (int i = 0; i < n; i++)
        ans += max((min(left[i], right[i]) - heights[i]), 0);
    return ans;
}
*/

int main()
{
    // int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int arr[] = {4,3,3,1,2,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << rainwater(arr,n) << endl;

    return 0;
}
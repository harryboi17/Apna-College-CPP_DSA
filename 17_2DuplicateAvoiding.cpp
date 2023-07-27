#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(vector<int> a, vector<vector<int>> &ans, int idx){
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        if (i != idx && a[i] == a[idx])
            continue;
        
        swap(a[i], a[idx]);
        helper(a, ans, idx+1);
        // swap(a[i], a[idx]);
    }
    
    
}

vector<vector<int>> permute(vector<int> nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    helper(nums, ans, 0);
    return ans;
}

int main(){
int n; cin>>n;

vector<int> a(n);
for(int &i : a){
    cin>>i;
}

vector<vector<int>> res = permute(a);

for(auto v : res ){
    cout<<endl;
    for(auto i : v){
        cout<<i<<" ";
    }
}

return 0;
}
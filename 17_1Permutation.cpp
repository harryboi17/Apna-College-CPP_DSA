#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a, int idx){
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++)
    {
        swap(a[i], a[idx]);
        permute(a, idx+1);
        swap(a[i], a[idx]); // doesnt need to swap again if we remove & from a
                            // because of & a gets updated due to permutes 
    }
    
}

/*
alternate trick:
sort(nums.begin(), nums.end());
do{
    ans.pushback(nums);
}
while(next_permutation(nums.begin(), nums.end()))
*/

int main(){
int n; cin>>n;

vector<int> a(n);
for(int &i : a){
    cin>>i;
}

permute(a,0);

for(auto v : ans ){
    cout<<endl;
    for(auto i : v){
        cout<<i<<" ";
    }
}
return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define forr(i,s,e) for(int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

vi prefix_func(string s){
    int n = s.size();
    vector<int> pi(n,0);

    forr(i,1,n){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        
        if(s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main(){
string s = "apnancollegenan";
string t = "aabaabha";
vector<int> prefix = prefix_func(t);
for(auto i : prefix)
    cout<<i<<" ";
cout<<endl;

int pos(-1); 
int i = 0, j = 0;
while(i < s.size()){
    if(s[i] == t[j]){
        i++; j++;
    }
    else{
        if(j != 0)
            j = prefix[j-1];
        else
            i++;
    }

    if(j == t.size()){
        pos = i - t.size();
        break;
    }
}
cout<<pos<<endl;
return 0;
}
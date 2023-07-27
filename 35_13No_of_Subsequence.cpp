#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define forr(i,s,e) for(int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

void subseq(string s, queue<int> que, int &ans){ //O(3^x * n)
    string abc = "abc";
    if(que.empty()){
        int Ccount = 0, Bans = 0, Aans = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == 'c')
                Ccount++;
            else if(s[i] == 'b')
                Bans += Ccount;
            else if(s[i] == 'a')
                Aans += Bans;
        }
        
        cout<<s<<" "<<Aans<<endl;
        ans += Aans;
        return;
    }

    int first_qmark = que.front();
    que.pop();
    forr(i,0,abc.size()){
        s[first_qmark] = abc[i];   
        subseq(s, que, ans);
    }
}

int ApnaCollege(string s){ //O(n)
    int e = 1, a = 0, ab = 0, abc = 0;
    forr(i,0,s.size()){
        if(s[i] == 'a')
            a += e;
        if(s[i] == 'b')
            ab += a;
        if(s[i] == 'c')
            abc += ab;
        if(s[i] == '?'){
            abc = 3*abc + ab;
            ab = 3*ab + a;
            a = 3*a + e;
            e = 3*e;
        }
    }
    return abc;
}

int main(){
string s; cin>>s;
queue<int> que;
forr(i,0,s.size())
    if(s[i] == '?')
        que.push(i);

int ans = 0;
subseq(s, que, ans);
cout<<endl<<ans<<endl;
cout<<ApnaCollege(s)<<endl;
return 0;
}
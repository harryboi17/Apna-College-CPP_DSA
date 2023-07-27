#include <iostream>
#include <deque>
#include <vector>
using namespace std;
/*
1) push_front(x) and push_back(x)
2) d1.front() and dq.back()
3) pop_front(x) and pop_back(x);
4) dq.size()
5) dq.empty()
*/
int main(){
/*
// ************************BASIC************************
deque<int> dq;
dq.push_back(1);
dq.push_back(2);
dq.push_back(3);
dq.push_back(4);

for(auto i : dq){
    cout<<i<<" ";
}
cout<<endl;
dq.pop_back();
dq.pop_front();

deque<int> :: iterator it ;
for (it = dq.begin() ; it != dq.end(); it++)
{
    cout<<*it<<" ";
}
*/
/*
deque<int> dq;
dq.push_front(1);
dq.push_front(2);
dq.push_front(3);
dq.push_front(4);

cout<<dq[0];
*/

//*****************MAXIMUM WINDOW QUESTION*****************8
 int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        int k; cin>>k;
        vector<int> v(n);
        for(auto &i : v){
            cin>>i;
        }
        
        deque<int> q;
        vector<int> ans;
        for (int i = 0; i<k; i++) {
            while (!q.empty() && v[q.back()] < v[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(v[q.front()]);
        
        for (int i = k; i<n; i++) {
            if (q.front() == i-k) {
                q.pop_front();
            }
            while (!q.empty() && v[q.back()] < v[i]) {
                q.pop_back();    
            }
            q.push_back(i);
            ans.push_back(v[q.front()]);
        }
        
        for(auto i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }   

return 0;
}
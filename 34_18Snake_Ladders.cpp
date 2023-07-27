#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
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

int main(){
int ladders, snakes;

unordered_map<int, int> lad;
unordered_map<int, int> snake;

cin>>ladders;
forr(i,0,ladders){
    int u, v; cin>>u>>v;
    lad[u] = v;
}
cin>>snakes;
forr(i,0,snakes){
    int u, v; cin>>u>>v;
    snake[u] = v;
}

int moves = 0;
queue<int> q;
q.push(1);

bool found = false;
vi vis(101, 0);
vis[1] = 1;

while (!q.empty() && !found)
{
    int sz = q.size();
    while (sz--)
    {
        int t = q.front();
        q.pop();
        forr(i,1,7){
            if(t+i == 100)
                found = true;

            if(t+i <= 100 && lad[t+i] && !vis[lad[t+i]]){
                vis[lad[t+i]] = 1;
                if(lad[t+i] == 100)
                    found = true;
                q.push(lad[t+i]);
            }
            else if(t+i <= 100 && snake[t+i] && !vis[snake[t+i]]){
                vis[snake[t+i]] = 1;
                if(snake[t+i] == 100)
                    found = true;
                q.push(snake[t+i]);
            }
            else if(t+i <= 100 && !vis[t+i] && !snake[t+i] && !lad[t+i]){
                vis[t+i] = 1;
                q.push(t+i);
            }
        }
    }
    moves++;
}
if(found)
    cout<<moves<<" ";
else
    cout<<"Cant reach the end"<<endl;

return 0;
}
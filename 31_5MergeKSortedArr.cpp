#include <iostream>
#include <vector>
#include <queue>
#define forr(i, s, e) for (int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
using namespace std;
//Time Complexity : O(nlog(k));
/*
5
4  1 3 6 8
3  1 1 2
5  5 6 7 8 9
2  2 9
3  3 4 8
*/
int main()
{
    cout<<"Enter total number of vectors : ";
    int k; cin >> k;
    vector<vi> a(k);
    forr(i,0,k){
        cout<<"Enter the size of vector "<<i<<" : ";
        int size; cin>>size;
        a[i] = vi(size);
        forr(j,0,size)
            cin>>a[i][j];
    }

    vi idx(k,0);

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    forr(i,0,k)
        pq.push({a[i][0], i});

    vi ans;
    
    while (!pq.empty())
    {
        pii x = pq.top();
        pq.pop();

        ans.push_back(x.first);

        if(idx[x.second] + 1 < a[x.second].size())
            pq.push({a[x.second][++idx[x.second]], x.second});
    }
    
    for(auto i : ans){
        cout<<i<<" ";
    }

    return 0;
}
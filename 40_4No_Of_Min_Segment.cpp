#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <cmath>
#define forr(i, s, e) for (int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr) / sizeof(arr[0])
using namespace std;
const int N = 1e5 + 2;
pair<int, int> trees[4 * N];
int arr[N];
/*
9
6 8 -1 2 17 1 3 2 4
1
2 8
2
7 -1
-1
*/

void build(int node, int st, int en){ //built in O(2n -1) time
    if (st == en){
        trees[node].ff = arr[st];
        trees[node].ss = 1;
        return;
    }

    int mid = (st + en) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);

    if(trees[2 * node].ff < trees[2 * node + 1].ff)
        trees[node] = trees[2*node];
    else if(trees[2 * node].ff > trees[2 * node + 1].ff)
        trees[node] = trees[2*node + 1];
    else{
        trees[node].ff = trees[2*node].ff;
        trees[node].ss = trees[2*node].ss + trees[2*node + 1].ss;
    }
}

pair<int, int> query(int node, int st, int en, int l, int r){//done in log(n) time
    if (st > r || en < l)
        return {INT_MAX, -1};

    if (l <= st && r >= en) // l... st...en ...r
        return trees[node];

    int mid = (st + en) / 2;

    pii q1 = query(2 * node, st, mid, l, r);
    pii q2 = query(2 * node + 1, mid + 1, en, l, r);
    pii q;
    
    if(q1.first < q2.ff)
        q = q1;
    else if(q1.ff > q2.ff)
        q = q2;
    else{
        q.ff = q1.ff;
        q.ss = q2.ss + q1.ss;
    }
    return q;
}

void update(int node, int st, int en, int idx, int val)
{
    if (st == en && st == idx){
        arr[st] = val;
        trees[node].ff = val;
        trees[node].ss = 1;
        return;
    }

    int mid = (st + en) / 2;
    if (mid >= idx)
        update(2 * node, st, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, en, idx, val);

    if(trees[2 * node].ff < trees[2 * node + 1].ff)
        trees[node] = trees[2*node];
    else if(trees[2 * node].ff > trees[2 * node + 1].ff)
        trees[node] = trees[2*node + 1];
    else{
        trees[node].ff = trees[2*node].ff;
        trees[node].ss = trees[2*node].ss + trees[2*node + 1].ss;
    }
}

int main()
{
    int n;
    cin >> n;
    forr(i, 0, n)
        cin>>arr[i];

    build(1, 0, n - 1);
    forr(i, 1, 2 * n)
        cout << trees[i].ff << " ";
    cout << endl;

    while (1){
        int type;
        cout << "Enter the type : ";
        cin >> type;
        if (type == -1)
            break;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            pii ans = query(1, 0, n - 1, l, r);
            cout << ans.ff << " " << ans.ss  << endl;
        }
        if (type == 2)
        {
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
            pii ans = query(1, 0, n - 1, 0, n-1);
            cout << ans.ff << " " << ans.ss  << endl;
        }
    }

    return 0;
}
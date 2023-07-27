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

void change(vector<vector<char>> &v, int x, int y){
    v[x][y] = '*';
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    forr(i,0,4){
        int cx = x + dx[i];
        int cy = y + dy[i];

        if(cx>=0 && cy >= 0 && cx < v.size() && cy < v[0].size() && v[cx][cy] == 'O')
            change(v,cx,cy);
    }
}

int main(){
int n, m; cin>>n>>m;
vector<vector<char>> v(n, vector<char>(m));
forr(i,0,n)
    forr(j,0,m)
        cin>>v[i][j];

forr(i,0,n)
    forr(j,0,m)
        if(i == 0 || j == 0 || i == v.size()-1 || j == v[0].size()-1)
            if(v[i][j] == 'O')
                change(v,i,j);

forr(i,0,n)
    forr(j,0,m)
        if(v[i][j] == 'O')
            v[i][j] = 'X';

forr(i,0,n)
    forr(j,0,m)
        if(v[i][j] == '*')
            v[i][j] = 'O';

cout<<endl;
forr(i,0,n){
    forr(j,0,m)
        cout<<v[i][j]<<" ";
    cout<<endl;
}

return 0;
}

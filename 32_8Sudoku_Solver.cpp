#include <iostream>
#include <vector>
#include <map>
#define forr(i,s,e) for(int i = s; i < e; i++)
#define vi vector<int>
#define pii pair<int, int>
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define arrSize(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

void helper(int r, int c, vector<vi> &a, map<pii, map<int, int>> &m, vector<map<int, int>> &row, vector<map<int, int>> &col){
    if(r == 9){
        forr(i,0,9){
            forr(j,0,9){
                cout<< a[i][j];
                if((j+1)%3 == 0)
                    cout<<" ";
            }cout<<endl;
            if((i+1)%3 == 0)
                cout<<endl;
        }
        return;
    }
    if(c == 9){
        helper(r+1, 0, a, m, row, col);
        return;
    }
    if(a[r][c] != 0){
        helper(r, c+1, a, m, row, col);
        return;
    }
    forr(i,1,10){
        int rw = r/3, cl = c/3;
        if(!m[{rw, cl}][i] && !row[r][i] && !col[c][i]){

            m[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            a[r][c] = i;

            helper(r, c+1, a, m, row, col);

            m[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c] = 0;

        }
    }
}

void SudokuSolver(vector<vi> &a){
    map<pii, map<int, int>> m;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);

    forr(i,0,9)
        forr(j,0,9)
            if(a[i][j] != 0){
                m[{i/3, j/3}][a[i][j]] = 1;
                row[i][a[i][j]] = 1;
                col[j][a[i][j]] = 1;
            }
    
    helper(0, 0, a, m, row, col);
}

int main(){
vector<vi> a = {
    {5, 3, 0,  0, 7, 0,  0, 0, 0},
    {6, 0, 0,  1, 9, 5,  0, 0, 0},
    {0, 9, 8,  0, 0, 0,  0, 6, 0},

    {8, 0, 0,  0, 6, 0,  0, 0, 3},
    {4, 0, 0,  8, 0, 3,  0, 0, 1},
    {7, 0, 0,  0, 2, 0,  0, 0, 6},
    
    {0, 6, 0,  0, 0, 0,  2, 8, 0},
    {0, 0, 0,  4, 1, 9,  0, 0, 5},
    {0, 0, 0,  0, 8, 0,  0, 7, 9}
};

SudokuSolver(a);
return 0;
}
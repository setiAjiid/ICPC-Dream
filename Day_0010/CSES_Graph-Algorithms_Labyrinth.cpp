// Keputih, Surabaya, Indonesia - 24/05/25 - 19.20 (After off 7 days on CP)
// Reviewing about graph in CSES (for graph test preparation on my college)

#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define ull unsigned long long
#define day_10 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void backtrack(int x, int y, vector<vector<char>> &dir){
    stack<char> ans;
    while (dir[x][y] != 'A'){
        ans.push(dir[x][y]);
        if (dir[x][y] == 'U') x++;
        else if (dir[x][y] == 'R') y--;
        else if (dir[x][y] == 'D') x--;
        else if (dir[x][y] == 'L') y++;
    }

    cout << ans.size() << el;
    while (!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    exit(0);
}

void bfs(int x, int y, int posRow[], int posCol[], vector<string> &v, vector<vector<char>> &dir){
    dir[x][y] = 'A'; //stop point

    queue<pair<int, int>> q;
    string direction = "URDL";
    q.push({x, y});
    while (!q.empty()){
        int xf = q.front().first; //x front
        int yf = q.front().second; //y front
        q.pop();
        for (int i = 0; i < 4; i++){
            int xn = xf + posRow[i]; //x next
            int yn = yf + posCol[i]; //y next
            if (xn >= 0 && xn < (int)v.size() && yn >= 0 && yn < (int)v[0].size() && v[xn][yn] != '#' && dir[xn][yn] == '0'){
                dir[xn][yn] = direction[i];
                if (v[xn][yn] == 'B'){
                    cout << "YES" << el;
                    backtrack(xn, yn, dir);
                    break;
                }
                q.push({xn, yn});
            }
        }
    }

}


int main(){
    day_10;
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &inp: v){
        cin >> inp;
    }

    vector<vector<char>> dir(n, vector<char> (m, '0')); //0 as "still not visited"
    int posRow[] = {-1, 0, 1, 0};
    int posCol[] = {0, 1, 0, -1};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] == 'A'){
                bfs(i, j, posRow, posCol, v, dir);
                break;
            }
        }
    }
    cout << "NO" << el;
}



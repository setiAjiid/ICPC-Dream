// Keputih, Surabaya, Indonesia - 24/05/25 - 09.23 (After off 7 days on CP)
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

void dfs(int x, int y, int posRow[], int posCol[], vector<string> &v, vector<vector<bool>> &vis){
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++){
        int nx = x + posRow[i];
        int ny = y + posCol[i];
        if (nx >= 0 && nx < (int)v.size() && ny >= 0 && ny < (int)v[0].size() && v[nx][ny] == '.' && !vis[nx][ny]){
            dfs(nx, ny, posRow, posCol, v, vis);
        }
    }
}

int main(){
    day_10;
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<vector<bool>> vis(n, vector<bool> (m, 0));
    int posRow[] = {-1, 0, 1, 0};
    int posCol[] = {0, 1, 0, -1};
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (v[i][j] != '#' && !vis[i][j]){
                dfs(i, j, posRow, posCol, v, vis);
                ans++;
            }
        }
    }
    cout << ans;
}

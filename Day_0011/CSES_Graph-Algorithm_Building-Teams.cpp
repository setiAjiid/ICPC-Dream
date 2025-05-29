// Keputih, Surabaya, Indonesia - 27/05/25 - 10.08 (Stuck)
//                              - 27/05/25 - 13.15 (Continuing)
//                              - 28/05/25 - 22.56 (Continuing again)
//                              - 29/05/25 - 10.08 (Continuing again and again lol)
// Reviewing about graph in CSES

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define day_11 ios::sync_with_stdio(0), cin.tie(0)
#define el '\n'

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int dfs(int node, vector<int> &color, vector<vector<int>> &v){
    for (auto adj: v[node]){
        if (color[adj] == -1){
            color[adj] = (color[node] + 1) % 2;
            if (!dfs(adj, color, v)) return 0;
        } else {
            if (color[adj] == color[node]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    day_11;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<int> color(n + 1, -1);
    bool ok = 1;
    for (int i = 1; i <= n; i++){
        if (color[i] == -1){
            color[i] = 0;
            ok = dfs(i, color, v);
            if (!ok) {
                cout << "IMPOSSIBLE" << el;
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        cout << color[i] + 1 << " ";
    }
}

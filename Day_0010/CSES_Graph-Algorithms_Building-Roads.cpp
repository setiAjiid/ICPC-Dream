// Keputih, Surabaya, Indonesia - 24/05/25 - 20-.30 (After off 7 days on CP)
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

void dfs(int node, vector<bool> &vis, vector<vector<int>> &v){
    vis[node] = 1;
    for (auto adj: v[node]){
        if (!vis[adj]){
            dfs(adj, vis, v);
        }
    }
}

int main(){
    day_10;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    vector<bool> vis(n + 1, 0);
    stack<int> ans;
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            ans.push(i);
            dfs(i, vis, v);
        }
    }

    cout << (ans.size() > 1 ? ans.size() - 1 : 0) << el;
    while (ans.size() > 1){
        cout << ans.top() << " ";
        ans.pop();
        cout << ans.top() << el;
    }
}


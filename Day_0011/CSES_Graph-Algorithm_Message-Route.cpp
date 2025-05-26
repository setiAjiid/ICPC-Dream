// Keputih, Surabaya, Indonesia - 26/05/25 - 22.15
// Reviewing about graph in CSES

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define el '\n'
#define day_11 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void print(int node, vector<int> &parent, vector<vector<int>> &v){
    stack<int> ans;
    while (node != 0){
        ans.push(node);
        node = parent[node];
    }
    cout << ans.size() << el;
    while (!ans.empty()){
        cout << ans.top() << " ";
        ans.pop();
    }
    exit(0);
}

void bfs(int node, vector<int> &parent, vector<vector<int>> &v){
    parent[node] = 0;
    queue<int> q;
    q.push(node);
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        for (auto adj: v[cur]){
            if (adj != parent[cur] && parent[adj] == -1){
                parent[adj] = cur;
                if (adj == (int)v.size() - 1){ //sz-1 cz zero base idx in vector v
                    print(adj, parent, v);
                }
                q.push(adj);
            }
        }
    }
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

    vector<int> parent(n + 1, -1);
    bfs(1, parent, v);
    cout << "IMPOSSIBLE" << el;
    return 0;
}

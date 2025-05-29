// Keputih, Surabaya, Indonesia - 29/05/25 - 12.07

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

void ans(int stop_start_node, int ref_node, vector<int> &parent){
    stack<int> st;
    st.push(stop_start_node);
    while (ref_node != stop_start_node){
        st.push(ref_node);
        ref_node = parent[ref_node];
    }
    st.push(stop_start_node);
    cout << st.size() << el;
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    exit(0);

}

void dfs(int node, vector<int> &parent, vector<vector<int>> &v){
    for (auto adj: v[node]){
        if (parent[adj] == -1){
            parent[adj] = node;
            dfs(adj, parent, v);
        } else {
            if (adj != parent[node]){
                ans(adj, node, parent);
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
    for (int i = 1; i <= n; i++){
        if (parent[i] == -1){
            parent[i] = 0;
            dfs(i, parent, v);
        }
    }
    cout << "IMPOSSIBLE";
}

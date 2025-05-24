// Keputih, Surabaya, Indonesia - 06/05/2025 - 22.55

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define el '\n'
#define day_2 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int change(string name, map<string, int> &mp, int *cnt){
    if (mp[name] == 0){
        (*cnt)++;
        mp[name] = (*cnt);
        return mp[name];
    } else {
        return mp[name];
    }
}

void dfs(int start, vector<vector<int>> &v, vector<bool> &vis, vector<int> &res){
    vis[start] = 1;
    for (auto adj: v[start]){
        if (!vis[adj]){
            res[adj] = 1 + res[start];
            dfs(adj, v, vis, res);
        }
    }
}

int main(){
    day_2;
    int n;
    cin >> n;
    int cnt = 0;
    map<string, int> mp;

    vector<vector<int>> v(205);
    vector<bool> vis(205, 0);
    for (int i = 0; i < n; i++){
        string name_1, link, name_2;
        cin >> name_1 >> link >> name_2;
        transform(name_1.begin(), name_1.end(), name_1.begin(), ::tolower);
        transform(name_2.begin(), name_2.end(), name_2.begin(), ::tolower);

        int parent = change(name_2, mp, &cnt);
        int child = change(name_1, mp, &cnt);

        v[parent].push_back(child);
    }

    vector<int> res(205, 0);
    res[1] = 1;
    dfs(1, v, vis, res);

    int ans = 0;
    for (int i = 0; i < (int)res.size(); i++) ans = max(ans, res[i]);
    cout << ans;
}

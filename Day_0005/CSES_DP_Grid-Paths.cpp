// Kepanjen, Malang, Indonesia - 10/05/25 - 16.20

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define el '\n'
#define day_5 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MOD = 1e9 + 7;
int main(){
    day_5;
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &inp: v) cin >> inp;

    vector<vector<int>> dp(n, vector<int> (n, 0));
    dp[0][0] = (v[0][0] == '*' ? 0 : 1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (v[i][j] == '*' || dp[i][j] != 0) {
                continue;
            }
            if (i - 1 >= 0) dp[i][j] = dp[i - 1][j];
            if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[n - 1][n - 1];
}

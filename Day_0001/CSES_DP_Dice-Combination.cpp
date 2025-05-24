// Keputih, Surabaya, Indonesia - 05/05/2025 - 20.28
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define day_1 ios::sync_with_stdio(0), cin.tie(0)
#define el '\n'

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace std;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MOD = 1e9 + 7;
int main(){
    day_1;
    int n;
    cin >> n;
    vector<ll> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++){
        ll ways = 0;
        for (int j = 1; j <= 6; j++){
            if (i >= j) ways += dp[i - j];
        }
        dp[i] = ways % MOD;
    }
    cout << dp[n];
}

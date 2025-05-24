// Kepanjen, Malang, Indonesia - 10/05/25 - 17.20

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
    int n, coin;
    cin >> n >> coin;
    vector<int> v(n);
    for (auto &inp: v) cin >> inp;

    vector<ll> dp(coin + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= coin; i++){
        for (int j = 0; j < n; j++){
            if (i - v[j] >= 0) dp[i] = (dp[i] + dp[i - v[j]]) % MOD;
        }
    }
    cout << dp[coin];
}

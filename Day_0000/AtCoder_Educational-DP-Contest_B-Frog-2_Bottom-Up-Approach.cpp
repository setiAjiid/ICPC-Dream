// Keputih, Surabaya, Indonesia - 04/05/2025 - 20.47
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define day_0 ios::sync_with_stdio(0), cin.tie(0)
#define el '\n'

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    day_0;
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    vector<ll> dp(n, 0);
    for (auto &inp: v) cin >> inp;

    for (int i = 1; i < n; i++){
        ll mini = INT_MAX;
        for (int j = 1; j <= k; j++){
            if (i >= j) mini = min(mini, abs(v[i] - v[i - j]) + dp[i - j]);
        }
        dp[i] = mini;
    }
    cout << dp[n - 1] << el;
}

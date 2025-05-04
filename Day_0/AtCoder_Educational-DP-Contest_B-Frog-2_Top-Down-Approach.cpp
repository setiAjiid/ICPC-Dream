//Keputih, Surabaya, Indonesia - 04/05/2025 - 20.39
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

ll f(int n, int k, vector<ll> &dp, vector<int> &v){
    if (n < 1) return 0;
    if (dp[n] != -1) return dp[n];

    ll mini = INT_MAX;
    for (int i = 1; i <= k; i++){
        if (n >= i) mini = min(mini, abs(v[n] - v[n - i]) + f(n - i, k, dp, v));
    }
    return dp[n] = mini;
}

int main(){
    day_0;
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    vector<ll> dp(n, -1);
    for (auto &inp: v) cin >> inp;
    f(n - 1, k, dp, v);
    cout << dp[n - 1] << el;
}

// Keputih, Surabaya, Indonesia - 04/05/2025 19.55
#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define ull unsigned long long
#define day_0 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    day_0;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &inp: v) cin >> inp;
    vector<ll> dp(n, -1);
    dp[0] = 0;
    for (int i = 1;  i < n; i++){
        ll one = abs(v[i] - v[i - 1]) + dp[i - 1];
        ll two = (i >= 2 ? abs(v[i] - v[i - 2]) + dp[i - 2] : LLONG_MAX);
        dp[i] = min(one, two);
    }
    cout << dp[n - 1] << el;
}

//Keputih, Surabaya, Indonesia - 04/05/2025 - 19.47 WIB
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

int f(int n, vector<int> &dp, vector<int> &v){
    if (n == 0){
        return 0;
    }
    if (dp[n] != -1) return dp[n];
    ll one = abs(v[n] - v[n - 1]) + f(n - 1, dp, v);
    ll two = (n >= 2 ? abs(v[n] - v[n - 2]) + f(n - 2, dp, v) : LLONG_MAX);
    return dp[n] = min(one, two);
}

int main(){
    day_0;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &inp: v) cin >> inp;
    vector<int> dp(n, -1);
    f(n - 1, dp, v);
    cout << dp[n - 1] << el;
}

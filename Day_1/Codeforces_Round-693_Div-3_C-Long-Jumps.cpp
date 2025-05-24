// Keputih, Surabaya, Indonesia - 05/05/2025 - 20.59
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

int main(){
    day_1;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &inp: v) cin >> inp;
        reverse(v.begin(), v.end());

        vector<ll> dp(n + 1, 0);
        for (int i = 0; i < n; i++){
            if (i - v[i] >= 0) dp[i] = v[i] + dp[i - v[i]];
            else dp[i] = v[i];
        }

        ll maks = INT_MIN;
        for (int i = 0; i < n; i++){
            maks = max(maks, dp[i]);
        }
        cout << maks << el;

    }
}

// Keputih, Surabaya, Indonesia - 08/05/25 - 22.27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define el '\n'
#define day_4 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    day_4;
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (3));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            cin >> v[i][j];
        }
    }

    vector<vector<ll>> dp(n, vector<ll> (3));
    for (int i = 0; i < 3; i++){
        dp[0][i] = v[0][i];
    }
    for (int i = 1; i < n; i++){ //this is "day"
        for (int j = 0; j < 3; j++){ //choice of act (what if I'm doing an act 1, or act 2, or maybe act 3?) in that day
            ll maks = 0;
            for (int k = 0; k < 3; k++){ //find the val max of act in yesterday
                if (k != j) maks = max(maks, dp[i - 1][k]);
            }
            dp[i][j] = v[i][j] + maks;
        }
    }

    //find max point in the final days
    ll ans = 0;
    for (int i = 0; i < 3; i++){
        ans = max(dp[n - 1][i], ans);
    }
    cout << ans;
}

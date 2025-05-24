// Kepanjen, Malang, Indonesia - 11/05/25 - 11.16

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define el '\n'
#define day_6 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    day_6;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &inp: v) cin >> inp;

        vector<vector<ll>> dp(n, vector<ll> (2));
        dp[0][0] = v[0]; // 0 as Friend
        dp[0][1] = 1e9; //1 as me, can't pick first
        for (int i = 1; i < n; i++){
            //myfriend's pick
            ll pick_1 = v[i] + dp[i - 1][1];
            ll pick_2 = v[i - 1] + v[i] + (i >= 2 ? dp[i - 2][1] : 0); //keluar dr batas. dijadiin 0. Soalnya ini turn-nya ur friend
            dp[i][0] = min(pick_1, pick_2);
            //my turn
            pick_1 = dp[i - 1][0];
            pick_2 = (i >= 2 ? dp[i - 2][0] : 1e9); //klo kluar batas? Ga boleh dipake, ini soalnya myturn, yg mana ga boleh pick pertama kali
            dp[i][1] = min(pick_1, pick_2);
        }

        cout << min(dp[n - 1][0], dp[n - 1][1]) << el;
    }
}

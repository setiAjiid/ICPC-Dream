// Keputih, Surabaya, Indonesia - 06/05/2025 - 22.27

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define el '\n'
#define day_2 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    day_2;
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= min(n, 9); i++){
        dp[i] = 1;
    }
    for (int i = 10; i <= n; i++){
        int num = i, mini = INT_MIN;
        while (num != 0){
            mini = max(num % 10, mini);
            num /= 10;
        }
        dp[i] = 1 + dp[i - mini];
    }
    cout << dp[n];
}

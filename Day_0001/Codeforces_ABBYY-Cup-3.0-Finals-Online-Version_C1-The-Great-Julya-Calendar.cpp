// Keputih, Surabaya, Indonesia - 05/05/2025 - 21.29
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
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= min(n, 9); i++){
        dp[i] = 1;
    }
    for (int i = 10; i <= n; i++){
        int number = i, mini = INT_MAX;
        while (number != 0){
            int digit = number % 10;
            number /= 10;
            if (digit == 0) continue;
            mini = min(mini, 1 + dp[i - digit]);
        }
        dp[i] = mini;
    }
    cout << dp[n];
}

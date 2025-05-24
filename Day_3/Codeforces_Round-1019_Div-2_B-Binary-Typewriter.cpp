// Keputih, Surabaya, Indonesia - 07/05/25 - 23.01

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define el '\n'
#define day_3 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    day_3;
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool ch = 0;
        int cnt = 0, ans = 0;
        char fi = s[0], last = s[n - 1];
      
        for (int i = 0; i < n; i++){
            if (s[i] == '1'){
                if (!ch) {
                    cnt++;
                    ch = 1;
                    ans += 2;
                } else ans++;
            } else if (s[i] == '0'){
                if (ch) {
                    cnt++;
                    ch = 0;
                    ans += 2;
                } else {
                    if (i == 0) cnt++;
                    ans++;
                }
            }
        }

        if (cnt == 3 && fi == '0') ans--;
        else if (cnt >= 3) ans -= 2;
        else if (fi == '1' && last == '0') ans--;

        cout << ans << el;
    }
}

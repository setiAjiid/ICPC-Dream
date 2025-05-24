// Keputih, Surabaya, Indonesia - 17/05/25 - 21.30 (After off 3 days on CP)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define el '\n'
#define keep_grinding ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


int main(){
    keep_grinding;
    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &inp: v) cin >> inp;

        bool ch = 0, zero = (v[0] == 0 ? 1 : 0);
        for (int i = 1; i < n; i++){
            if (v[i] == 0) zero = 1;
            if (v[i] == v[i - 1] && v[i] == 0) {
                ch = 1;
                break;
            }
        }
        if (zero == 0) ch = 1;
        cout << (ch ? "YES" : "NO") << el;
    }
}

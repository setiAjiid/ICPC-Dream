// Keputih, Surabaya, Indonesia - 17/05/25 - 20.37 (After off 3 days on CP)

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

        int maks = 0, idx = 0, same = 0;
        for (int i = 0; i < n; i++){
            if (v[0] == v[i]) same++;
            if (maks < v[i]){
                maks = v[i];
                idx = i;
            }
        }
        if (same == n) cout << "No" << el;
        else {
            cout << "Yes" << el;
            for (int i = 0; i < n; i++){
                if (idx == i) cout << 1 << " ";
                else cout << 2 << " ";
            }
            cout << el;
        }
    }
}

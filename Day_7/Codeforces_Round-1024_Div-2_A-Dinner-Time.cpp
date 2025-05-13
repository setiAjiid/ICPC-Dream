// Kepanjen, Malang, Indonesia - 11/05/25 - 22.00
// Got WA in 12/05/2025 - 07.34 - Then OVT and make me down
// Upsolve in 13/05/25 - 18.10

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
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        if ((n % p != 0) || m - (q * (int)(n/p)) == 0) cout << "YES" << el;
        else cout << "NO" << el;
    }
}

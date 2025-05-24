// Kepanjen, Malang, Indonesia - 11/05/25 - 22.52

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define el '\n'
#define day_7 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    day_7;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[i] = abs(x);
        }
        int fi = v[0], idx = -1, kanan = 0;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++){
            if (v[i] > fi) kanan++;
        }
        //at least harus dapet jumlah elemen bagian kanan > (n - 1)/2
        if (kanan >= (n - 1)/2) cout << "YES" << el;
        else cout << "NO" << el;
    }
}

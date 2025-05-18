// Keputih, Surabaya, Indonesia - 17/05/25 - 21.42 (After off 3 days on CP)
// Keputih, Surabaya, Indonesia - 18/05/25 - 12.28  (After Got WA in yesterday's Contest)

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
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        int atas, bawah,  kiri, kanan;
        int b_atas = 1, b_bawah = n, b_kiri = 1, b_kanan = m;
        int x_mid = x, y_mid = y, maks = 0;

        atas = abs(b_atas - x_mid); bawah = abs(b_bawah - x_mid);
        kiri = abs(b_kiri - y_mid); kanan = abs(b_kanan - y_mid);

        maks = max(kiri * n, max(kanan * n, max(bawah * m, atas * m)));

        ll col, row;
        vector<pair<int, int>> hasil;

        col = y - 1 + 1;
        row = n;
        hasil.push_back({row, col});

        col = m - y + 1;
        row = n;
        hasil.push_back({row, col});

        row = n - x + 1;
        col = m;
        hasil.push_back({row, col});

        row = x - 1 + 1;
        col = m;
        hasil.push_back({row, col});

        ll ans_c = 0, ans_r = 0;
        ll ans = LLONG_MAX;
        for (auto [row, col]: hasil){
            ans_c = 0, ans_r = 0;
            while (col > 1){
                col = col/2 + (col % 2 != 0 ? 1 : 0);
                ans_c++;
            }
            while (row > 1){
                row = row/2 + (row % 2 != 0 ? 1 : 0);
                ans_r++;
            }
            ans = min(ans, ans_c + ans_r);
        }

        cout << 1 + ans << el;

    }
}

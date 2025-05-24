// Kepanjen, Malang, Indonesia - 13/05/25 - 21.30

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define day_8 ios::sync_with_stdio(0), cin.tie(0) //Butuh support system :)
#define el '\n'

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int med(int k, ordered_set &os, vector<int> &v){
    int block = 0, n = v.size();
    for (int i = 0; i < n - 1; i++){
        pair<int, int> tmp = {v[i], i};
        os.insert(tmp);
        int mid = os.size() / 2 - ((os.size() % 2 == 0) ? 1 : 0);
        if (os.find_by_order(mid)->first <= k) {
            block++;
            os.clear();
            if (i == 0 && i + 1 < n - 1 && v[i + 1] > k){
                i++;
            }
            if (block == 2) {
                break;
            }
        }
    }
    os.clear();
    return block;
}

int main(){
    day_8;
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &inp: v) cin >> inp;

        ordered_set os;
        int block = 0;
        //there are 3 cases

        //case 1 (kiri + tengah + dump)
        block = med(k, os, v);
        if (block == 2) {
            cout << "Yes" << el;
            continue;
        }

        //case 2 (kanan + tengah + dump)
        reverse(v.begin(), v.end());
        block = med(k, os, v);
        if (block == 2) {
            cout << "Yes" << el;
            continue;
        }

        //case 3 (kanan + kiri + dump)
        int idx = 0;
        block = 0;
        for (int i = 0; i < n - 1; i++){
            os.insert({v[i], i});
            int mid = os.size() / 2 - (os.size() % 2 == 0 ? 1 : 0);
            if (os.find_by_order(mid)->first <= k) {
                block++;
                os.clear();
                idx = i + 1;
                break;
            }
        }

        for (int i = n - 1; i > idx; i--){
            os.insert({v[i], i});
            int mid = os.size() / 2 - (os.size() % 2 == 0 ? 1 : 0);
            if (os.find_by_order(mid)->first <= k) {
                block++;
                os.clear();
                if (i == n && i - 1 > idx && v[i - 1] > k){
                    i--;
                }
                break;
            }
        }

        if (block == 2) {
            cout << "Yes" << el;
            continue;
        } else {
            cout << "No" << el;
        }
    }
}

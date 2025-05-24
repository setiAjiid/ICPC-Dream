// Keputih, Surabaya, Indonesia - 08/05/25 - 23.47

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define el '\n'
#define day_4 ios::sync_with_stdio(0), cin.tie(0)

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main(){
    day_4;
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++){
        cin >> v[i];
        mp[v[i]]++;
    }

    ll ans = mp[4];
    if (mp[3] >= mp[1]) {
        ans += mp[3];
        mp[1] = 0;
    } else {
        mp[1] -= mp[3];
        ans += mp[3];
    }

    if (mp[2] % 2 == 0) {
        mp[2] /= 2;
        ans += mp[2];
    } else {
        ans += (mp[2]/2);
        mp[2] = 1;
        mp[1] += 2;
    }
    ans += (mp[1]/4) + (mp[1] % 4 ? 1 : 0);
    cout << ans;

}

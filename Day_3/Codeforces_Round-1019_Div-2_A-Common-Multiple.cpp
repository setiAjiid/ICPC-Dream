// Keputih, Surabaya, Indonesia - 07/05/25 - 22.01

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
        set<int> st;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            st.insert(x);
        }
        cout << st.size() << el;
    }


}

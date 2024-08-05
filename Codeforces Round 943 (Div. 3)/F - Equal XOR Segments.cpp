#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,q;
    cin >> n >> q;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    auto x = a;
    for(int i = 1; i <= n;i++) x[i] ^= x[i-1];

    map<int,vector<int>> mp;
    for(int i = 0; i <= n; i++) {
        if(mp[x[i]].empty()) mp[x[i]].push_back(INT_MIN);
        mp[x[i]].push_back(i);
    }

    for(auto &p: mp) {
        p.second.push_back(INT_MAX);
    }

    while(q--) {
        int l, r;
        cin >> l >> r;

        if(x[l-1] == x[r]) {
            cout << "YES" << "\n";
            continue;
        }

        int v1 = x[l-1];
        int v2 = x[r];

        int idx1 = *prev(upper_bound(mp[v1].begin(), mp[v1].end(), r));
        int idx2 = *lower_bound(mp[v2].begin(), mp[v2].end(), l);

        if(idx1 > idx2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    cout << "\n";
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

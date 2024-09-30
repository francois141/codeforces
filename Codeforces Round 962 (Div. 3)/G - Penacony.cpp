#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n,m;
    cin >> n >> m;

    vector<int> values(n+1);

    while(m--) {
        int val = g();
        int a,b;
        cin >> a >> b;
        values[a] ^= val;
        values[b] ^= val;
    }

    for(int i = 1; i <= n;i++) values[i] ^= values[i-1];

    map<int,int> mp;
    for(int i = 1; i <= n;i++) mp[values[i]]++;

    int ans = 0;
    for(auto e: mp) ans = max(ans, e.second);
    cout << n - ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

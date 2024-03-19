#include <bits/stdc++.h>
#define int long long
using namespace std;

int msb(int x) {
    return 63 - __builtin_clzll(x);
}

void solve() {
    int n,m;
    cin >> n >> m;

    vector<int> ans;
    ans.push_back(n);

    // Step 1 : clear out upper mask
    int cleared = (n >> (msb(m)+1ll)) << (msb(m)+1ll);
    int cnt = __builtin_popcountll(cleared);

    if(cleared != 0) {
        if((n & (1ll << msb(m))) == 0 && cnt == 1) {
            cout << -1 << "\n";
            return;
        }

        if((n & (1ll << msb(m))) == 0) {
            n |= (1ll << msb(m));
            n -= (1ll << msb(n));
            ans.push_back(n);
        }
    }

    if(ans.back() != m) {
        ans.push_back(m);
    }

    cout << ans.size()-1 << "\n";
    for(auto e: ans) cout << e << " ";
    cout << "\n";
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

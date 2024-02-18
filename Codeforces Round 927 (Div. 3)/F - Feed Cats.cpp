#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> seg(m);
    for(int i = 0; i < m;i++) cin >> seg[i].first >> seg[i].second;

    sort(seg.begin(), seg.end());

    vector<int> dp(n+1);
    vector<vector<int>> vec(n+1);
    multiset<int> s;

    int idx = 0;
    for(int i = 1; i <= n;i++) {
        while(idx < seg.size() && seg[idx].first == i) {
            vec[seg[idx].second].push_back(seg[idx].first);
            s.insert(seg[idx].first);
            idx++;
        }

        dp[i] = dp[i-1];

        if(!s.empty()) {
            dp[i] = max(dp[i], dp[(*s.begin()) - 1] + (int)s.size());
        }

        for(auto e : vec[i]) {
            s.erase(s.find(e));
        }
    }

    cout << dp.back() << "\n";
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

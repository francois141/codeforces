#include <bits/stdc++.h>
#define int long long 
using namespace std;

pair<int,int> mex(vector<int> &a) {
    pair<int,int> out;
    set<int> s;
    for(auto e: a) s.insert(e);
    while(s.find(out.first) != s.end()) out.first++;
    s.insert(out.first); 
    while(s.find(out.second) != s.end()) out.second++;
    return out;
}

void solve() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> a(n);
    for(int i = 0; i < n;i++) {
        int l;
        cin >> l;
        a[i] = vector<int>(l);
        for(int j = 0; j < l;j++) cin >> a[i][j];
    }

    int maxVal = 0;

    for(auto e: a) {
        auto p = mex(e);
        maxVal = max(maxVal, p.second);
    }

    vector<vector<int>> graph(maxVal+1);

    for(auto e: a) {
        auto p = mex(e);
        graph[p.first].push_back(p.second);
    }

    vector<int> dp(maxVal + 1, 0);
    iota(dp.begin(), dp.end(), 0ll);

    int best = 0;

    // Now compute dp & best
    for(int i = maxVal; i >= 0;i--) {
        if(graph[i].size() == 1) {
            dp[i] = dp[graph[i][0]];
            best = max(best, i);
        } else if (graph[i].size() > 1) {
            for(auto e: graph[i]) {
                dp[i] = max(dp[i], dp[e]);
            }
            best = max(best, dp[i]);
        }
    }

    // Then on iterate pour each et get the best - take dp (only second or best)
    int ans = 0;
    for(int i = 0; i <= min(maxVal, m);i++) {
        ans += max(best, dp[i]);
    }

    if(m > maxVal) {
        ans -= maxVal * (maxVal + 1) / 2;
        ans += m * (m + 1) / 2;
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

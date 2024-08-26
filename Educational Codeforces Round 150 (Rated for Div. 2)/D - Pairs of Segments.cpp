#include <bits/stdc++.h>
#define int long long
using namespace std;

bool ok(pair<int,int> p1, pair<int,int> p2) {
    return p1.second >= p2.first;
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n+1);
    for (int i = 1; i <= n;i++) cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), [](auto e1, auto e2) {
        return e1.second < e2.second;
    });

    vector<int> idx(n+1);
    for(int i = 1; i <= n;i++) idx[i] = a[i].second;
    vector<int> dp(n+1);

    idx[0] = -1;
    dp[0] = 0;

    for(int i = 1; i <= n;i++) {
        int best = 0;
        for(int j = 1; j < i;j++) {
            if(ok(a[j], a[i])) {
                int l = lower_bound(idx.begin(), idx.end(), min(a[j].first,a[i].first)) - idx.begin() - 1;
                best = max(best, dp[l] + 2);
            }
        }
        dp[i] = max(dp[i-1], best);
    }

    cout << n -dp.back() << "\n";
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

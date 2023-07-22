#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> diff(k+1, vector<int>(1,0));
    vector<int> prev(k+1,0);

    for(int i = 1; i <= n;i++) {
        int idx;
        cin >> idx;
        diff[idx].push_back(i - prev[idx] - 1);
        prev[idx] = i;
    }

    for(int i = 1; i <= k;i++) {
        diff[i].push_back(n - prev[i]);
    }

    int ans = INT_MAX;
    for(int i = 1; i <= k;i++) {
        sort(diff[i].rbegin(), diff[i].rend());
        ans = min(ans, max(diff[i][0] / 2, diff[i][1]));

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

    return 0;
}

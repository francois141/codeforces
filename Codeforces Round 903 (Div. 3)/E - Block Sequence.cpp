#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= n;i++) {
        if(i + a[i] <= n) {
            dp[i + a[i]] = min(dp[i + a[i]], dp[i-1]);
        }

        dp[i] = min(dp[i], dp[i-1] + 1);
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
}

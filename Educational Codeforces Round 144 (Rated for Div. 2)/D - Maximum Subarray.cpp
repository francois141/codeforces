#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k,x;
    cin >> n >> k >> x;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MIN));
    dp[0][0] = 0;

    int ans = 0;

    for(int i = 1; i <= n;i++) {
        dp[i][0] = max(0ll,dp[i-1][0] + a[i] - x);
        for(int j = 1; j <= k;j++) {
            dp[i][j] = max(0ll,dp[i-1][j-1] + a[i] + x);
            if(i-1 >= j) {
                dp[i][j] = max(dp[i][j],dp[i-1][j] + a[i] - x);
            }
        }
    }

    for(int i = 1; i <= n;i++) {
        for(int j = 0; j <= k;j++) {
            if(k - j <= n - i) {
                ans = max(ans,dp[i][j]);
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

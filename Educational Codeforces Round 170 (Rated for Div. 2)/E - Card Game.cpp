#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353;

int add(int a, int b) {
    return (a + b) % K;
}

int mult(int a, int b) {
    return (a * b) % K;
}

int n,m;
vector<vector<int>> a;

int compute(int diff) {
    vector<int> dp(m/2+1-diff);
    dp[0] = 1;

    for(int i = 1; i <= m/2 + diff;i++) {
        vector<int> dp2(m/2+1 - diff);

        for(int j = 1; j <= m/2-diff;j++) {
            dp[j] = add(dp[j], dp[j-1]);
        }

        for(int j = max(i-2*diff, 0ll); j <= m/2-diff;j++) {
            dp2[j] = add(dp2[j], dp[j]);
        }

        dp = dp2;
    }

    return dp.back();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    a = vector<vector<int>>(n, vector<int>(m));
    for(int i = 0; i < n;i++) {
        for(int j = 0; j < m;j++) cin >> a[i][j];
    }

    vector<int> diffs(m/2+1);
    for(int i = 0; i <= m/2;i++) diffs[i] = compute(i);

    auto diffs2 = diffs;

    vector<int> dp(m/2+1);
    dp[0] = 1;

    for(int i = 1; i < n;i++) {
        vector<int> dp2(m/2+1);
        for(int j = m/2; j >= 0;j--) {
            for(int taille = 0; j - taille >= 0; taille++) {
                dp2[j] = add(dp2[j], mult(diffs2[taille],dp[j-taille]));
            }
        }
        dp = dp2;
    }

    int ans = 0;
    for(int i = 0; i <= m/2;i++) {
        ans = add(ans, mult(dp[i], diffs[i]));
    }
    cout << ans << "\n";

    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for(int i = 0; i < n;i++) {
        string s; cin >> s;
        for(int j = 0; j < n;j++) {
            matrix[i][j] = s[j] - '0';
        }
    }

    vector<vector<int>> dp(n, vector<int>(n));
    dp[0] = matrix[0];

    vector<vector<int>> swapped(n, vector<int>(n,0));
    swapped[0] = matrix[0];

    int ans = accumulate(dp[0].begin(), dp[0].end(), 0ll);

    for(int i = 1; i < n;i++) {
        for(int j = 0; j < n;j++) {
            int nbSwaps = swapped[i-1][j];

            if(j < n - 1) nbSwaps += dp[i-1][j+1];
            if(j > 0) nbSwaps += dp[i-1][j-1];
            if(j > 0 && j < n-1 && i >= 2) nbSwaps -= dp[i-2][j];

            int val = matrix[i][j] + nbSwaps;
            if(val % 2) {
                dp[i][j] = nbSwaps+1;
                swapped[i][j] = 1;
                ans++;
            } else {
                dp[i][j] = nbSwaps;
            }
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
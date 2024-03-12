#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> a;
vector<vector<int>> dp;

void solve() {
    cin >> n;

    a = vector<int>(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    n++;
    a.push_back(INT_MAX);

    dp = vector<vector<int>>(n+1,vector<int>(n+1, INT_MAX));
    dp[0][0] = 0;

    for(int i = 1; i <= n;i++) {
        for(int k = 0; k <= n;k++) {
           if(a[i-1] < a[i]) {
               dp[i][k] = min(dp[i][k],dp[i-1][k]);
           }
        }

        for(int k = 1; k <= n;k++) {
            dp[i][k] = min(dp[i][k], dp[i][k-1]);
            for(int j = 1; j <= i;j++) {
                if(a[j-1] < a[i]) {
                    dp[i][k] = min(dp[i][k], dp[j-1][k-1] + (i - j));
                }
            }
        }
    }

    for(int i = 1; i < n;i++) cout << dp.back()[i] << " ";
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; // or 1e9 + 7;

inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    vector<vector<int>> dp(k+1, vector<int>(n+1));
    vector<vector<int>> dp2(k+1, vector<int>(n+1));
    dp[0][0] = dp2[0][0] = 1;
    // Edge case, first two
    dp[1][2] = dp2[1][2] = 1;

    for(int curr = 1; curr <= k;curr++)  {
        for(int i = 1; i <= n;i++) {
            dp2[curr-1][i] = add(dp2[curr-1][i-1], dp[curr-1][i]);
        }

        for(int i = 1; i <= n;i++) {
            dp[curr][i] = add(dp[curr][i],dp[curr-1][i-1]);
            if(i-3 >= 0) dp[curr][i] = add(dp[curr][i],dp2[curr-1][i-3]);
        }
    }

    for(int i = 1; i <= n;i++) {
        dp[k][i] = add(dp[k][i], dp[k][i-1]);
        if(i-3 >= 0) dp[k][i] = add(dp[k][i],dp2[k][i-3]);

        dp2[k][i] = add(dp2[k][i-1], dp[k][i]);
    }

    // Special final transition
    dp[k][n] = add(dp[k][n], add(dp[k][n-2],dp[k-1][n-2]));

    cout << dp.back().back() << "\n";

    return 0;
}

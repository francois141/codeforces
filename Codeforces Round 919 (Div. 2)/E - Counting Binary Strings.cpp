#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; // or 1e9 + 7;

inline int mult(int a,int b) {return ((a%K)*(b%K)) % K;}
inline int add(int a,int b) {return ((a%K)+(b%K)) % K;}

void solve() {
    int n,k;
    cin >> n >> k;

    vector<vector<int>> dp(n+1, vector<int>(k,0));
    for(int i = 0; i < k;i++) dp[0][i] = 1;

    for(int i = 0; i < n;i++) {
        for(int j = 0; j < k;j++) {
            for(int l = 0; l < k && (l+j+1) <= k && (l+1) * (j+1) + i <= n;l++) {
                dp[i + (l+1) * (j+1)][l] = add(dp[i + (l+1) * (j+1)][l], dp[i][j]);
            }
        }
    }
    
    int ans = 0;
    for(auto e: dp.back()) ans = add(ans, e);
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

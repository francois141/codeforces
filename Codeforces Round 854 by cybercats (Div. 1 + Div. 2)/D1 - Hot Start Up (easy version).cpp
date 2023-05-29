#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    vector<int> a(n+1);
    a[0] = INT_MAX;
    for(int i = 1; i <= n;i++) {
        cin >> a[i]; 
        a[i]--;
    }

    vector<int> cold(k);
    vector<int> hot(k);

    for(int i = 0; i < k;i++) cin >> cold[i];
    for(int i = 0; i < k;i++) cin >> hot[i];

    vector<vector<int>> dp(n+1,vector<int>(k+1,LLONG_MAX));
    
    dp[0][k] = 0;

    for(int i = 1; i <= n;i++) {
        // Case we execute on a[i-1]
        for(int j = 0; j <= k;j++) {
            if(dp[i-1][j] != LLONG_MAX)
                dp[i][j] = dp[i-1][j] + ((a[i-1] == a[i]) ? hot[a[i]] : cold[a[i]]);
        }
        // Case we execute on previous
        for(int l = 0; l < k;l++) {
            if(a[i-1] != INT_MAX && dp[i-1][l] != LLONG_MAX) {
                dp[i][a[i-1]] = min(dp[i][a[i-1]], dp[i-1][l] + ((l == a[i]) ? hot[a[i]] : cold[a[i]]));
            } 
            if(a[i-1] != INT_MAX && dp[i-1][l] == LLONG_MAX) {
                dp[i][a[i-1]] = min(dp[i][a[i-1]], dp[i-1][k] + cold[a[i]]);
            } 
        }
    }

    cout << *min_element(dp.back().begin(), dp.back().end()) << "\n";
}

signed main() {

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
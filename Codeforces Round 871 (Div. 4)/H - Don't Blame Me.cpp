#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 1e9+7; 

inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}

void solve() {
    int n,nb;
    cin >> n >> nb;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(64,0));

    for(int i = 1; i <= n;i++) {
        for(int k = 0; k < 64;k++) {
            dp[i][a[i] & k] = add(dp[i][a[i] & k], dp[i-1][k]);
            dp[i][k] = add(dp[i][k], dp[i-1][k]);
        }
        dp[i][a[i]]++;
    }

    int ans = 0;

    for(int k = 0;k < 64;k++) {
        if(__builtin_popcountll(k) == nb) 
            ans = add(ans,dp.back()[k]);
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
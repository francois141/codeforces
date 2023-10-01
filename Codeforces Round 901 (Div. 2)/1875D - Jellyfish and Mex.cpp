#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    vector<int> freq(5006, 0);
    for(auto e: a) {
        if(e < 5005) {
            freq[e]++;
        }
    }

    int mex = 0;
    while(freq[mex]) mex++;

    vector<pair<int,int>> dp(mex + 1, {INT_MAX, INT_MAX});
    dp[mex] = {0, 0};

    int ans = mex * n;

    for(int i = mex - 1; i >= 0; i--) {
        for(int j = mex; j > i; j--) {
            pair<int,int> sec = {dp[j].first + j*(freq[i]-1) + i,dp[j].second + freq[i]};
            if(sec.first < dp[i].first) {
                dp[i] = sec;
                ans = min(ans, sec.first + (n - sec.second) * i);
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

    while(t--)
        solve();

    return 0;
}

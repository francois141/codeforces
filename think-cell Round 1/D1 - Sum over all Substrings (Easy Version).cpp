#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string s;

int compute(int from, int to) {
    vector<int> dp(n+1, 0);

    for(int i = from; i <= to;i++) {
        if(s[i] == '0') {
            dp[i] = dp[i-1];
        } else {
            dp[i] = dp[i-1] + 1;
        }

        for(int size = 1; size <= 3; size++) {
            dp[i] = min(dp[i], dp[max(i - size, from-1)] + 1);
        }
    }

    return dp[to];
}

void solve() {
    cin >> n;
    cin >> s;

    s = " " + s;

    int ans = 0;

    for(int to = 1; to <= n;to++) {
        for(int from = 1; from <= to;from++) {
            ans += compute(from,to);
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

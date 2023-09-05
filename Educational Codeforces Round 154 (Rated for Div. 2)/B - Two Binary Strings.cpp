#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string a,b;
    cin >> a >> b;

    a = " " + a;
    b = " " + b;

    vector<bool> dp(a.size());
    dp[0] = true;

    int n = a.size() - 1;

    for(int i = 1; i <= n;i++) {
        if(dp[i-1] && a[i] == b[i]) {
            dp[i] = true;
        }
        
        for(int j = i - 1;j > 0;j--) {
            if(dp[j-1] && a[j] == b[j] && a[j] == a[i] && a[i] == b[i]) {
                dp[i] = true;
            }
        }
    }

    if(dp.back()) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

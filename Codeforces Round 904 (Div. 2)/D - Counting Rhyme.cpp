#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>

#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }

    vector<int> dp(n + 1, 0);
    vector<bool> mask(n + 1, false);

    for (int i = n; i >= 1; i--) {
        int taken = 0;
        int already = 0;

        for (int j = i; j <= n; j += i) {
            taken += a[j];
            already += dp[j];
            if (a[i] != 0) {
                mask[j] = true;
            }
        }

        dp[i] = taken * (taken - 1) / 2 - already;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mask[i])
            ans += dp[i];
    }

    cout << n * (n - 1) / 2 - ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();
}

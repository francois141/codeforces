#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int w,f,n;
    cin >> w >> f >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int sum = accumulate(a.begin(), a.end(), 0ll);

    vector<bool> bit(sum+1,false);
    bit[0] = true;

    while(n--) {
        int x = a[n];
        for(int i = sum; i - x >= 0;i--) {
            bit[i] = bit[i] || bit[i-x];
        }
    }

    int ans = LLONG_MAX;

    for(int i = 0; i <= sum;i++) {
        if(!bit[i]) continue;

        double v1 = i;
        double v2 = sum - i;

        int time = max(ceil(v1/w), ceil(v2/f));

        ans = min(ans, time);
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
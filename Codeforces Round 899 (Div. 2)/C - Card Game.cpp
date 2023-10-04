#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    auto b = a;
    b.back() = max(0ll, b.back());
    for(int i = n-1;i >= 1;i--) {
        b[i] = max(0ll,b[i]) + b[i+1];
    }

    int ans = ((n % 2 == 1) ? b.back() : 0);
    for(int i = 1; i < n;i++) {
        ans = max(ans, ((i % 2 == 1) ? a[i] : 0) + b[i+1]);
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

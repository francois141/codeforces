#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m,d;
    cin >> n >> m >> d;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    int ans = 0;

    int sum = 0;
    multiset<int> s;

    for(int i = 0; i <= n;i++) {
        if(a[i] > 0) {
            sum += a[i];
            s.insert(a[i]);
        }

        if(s.size() > m) {
            sum -= *s.begin();
            s.erase(s.begin());
        }

        ans = max(ans, sum-i*d);
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
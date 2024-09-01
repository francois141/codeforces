#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    vector<int> l(n);
    vector<int> r(n);

    for(int i = 0; i < n;i++) cin >> l[i];
    for(int i = 0; i < n;i++) cin >> r[i];

    int ans = LLONG_MAX;

    multiset<int> s;
    int sum = 0;

    for(int i = 0; i < n;i++) {
        int size = r[i] - l[i] + 1;
        s.insert(size);
        sum += size;

        while(sum > k && !s.empty() && *s.begin() == 1) {
            sum--;
            s.erase(s.begin());
        }

        while(sum - *s.begin() >= k + (*s.rbegin())) {
            sum -= *s.begin();
            s.erase(s.begin());
        }

        if(sum >= k) {
            int partial = max(0ll,sum - k);
            int cost = r[i] + 2*s.size() - partial;
            ans = min(ans, cost);
        }
    }

    if(ans == LLONG_MAX) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
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

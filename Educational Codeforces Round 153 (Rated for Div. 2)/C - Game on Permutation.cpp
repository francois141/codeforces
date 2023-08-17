#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int ans = 0;

    vector<int> t;
    for (int i = 0; i < a.size(); i++) {
        auto it= lower_bound(t.begin(), t.end(), a[i]);

        if (it == t.end()) {
            t.push_back(a[i]);
            if(t.size() == 2) ans++;
        }
        else {
            *it = a[i];
            if(it - t.begin() == 1) ans++;
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

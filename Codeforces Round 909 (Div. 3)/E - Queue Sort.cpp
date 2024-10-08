#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    auto it = min_element(a.begin(), a.end());
    if(!is_sorted(it, a.end())) {
        cout << -1 << "\n";
        return;
    }

    cout << it - a.begin() << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

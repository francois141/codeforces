#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    vector<int> b(n);
    for(int i = 0; i < n;i++) cin >> b[i];

    int v1 = accumulate(a.begin(), a.end(), 0ll) + n*(*min_element(b.begin(), b.end()));
    int v2 = accumulate(b.begin(), b.end(), 0ll) + n*(*min_element(a.begin(), a.end()));

    cout << min(v1,v2) << "\n";
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

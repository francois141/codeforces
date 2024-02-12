#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int ans = 0;

    int maxVal = a.back();
    a.pop_back();
    while(!a.empty()) {
        int coups =  ceil(a.back() / (double)maxVal);
        ans += coups - 1;
        maxVal = min(maxVal, a.back() / coups);
        a.pop_back();
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
}

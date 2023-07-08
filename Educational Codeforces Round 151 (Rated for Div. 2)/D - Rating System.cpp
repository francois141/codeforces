#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    partial_sum(a.begin(),a.end(), a.begin());

    int ans = 0;
    int diff = 0;

    int big = 0;

    for(int i = 1; i <= n;i++) {
        big = max(big, a[i]);
        if(big - a[i] > diff) {
            diff = big - a[i];
            ans = big;
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
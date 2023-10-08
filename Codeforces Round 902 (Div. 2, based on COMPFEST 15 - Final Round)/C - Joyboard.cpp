#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m,k;
    cin >> n >> m >> k;

    if(k > 3) {
        cout << 0 << "\n";
    } else if(k == 2) {
        int val = min(n-1,m) + m / n;
        cout << val << "\n";
    } else if(k == 3) {
        if(m > n) {
            int val = m - n + 1 - m/n;
            cout << val << "\n";
        } else {
            cout << 0 << "\n";
        }
    } else {
        cout << 1 << "\n";
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

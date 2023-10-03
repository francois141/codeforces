#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a,b,n;
    cin >> a >> b >> n;

    while(n--) {
        int x;
        cin >> x;
        b += min(a-1, x);
    }

    cout << b << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

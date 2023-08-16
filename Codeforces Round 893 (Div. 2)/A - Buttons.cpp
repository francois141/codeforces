#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a,b,c;
    cin >> a >> b >> c;

    a += ceil(c / 2.0);
    b += floor(c / 2.0);

    cout << ((a > b) ? "First" : "Second") << "\n";
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

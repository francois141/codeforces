#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int b,c,h;
    cin >> b >> c >> h;

    int v1 = 2*(c + h) + 1;
    int v2 = b + b-1;

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

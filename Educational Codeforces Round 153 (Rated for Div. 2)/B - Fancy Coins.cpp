#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int m,k,a1,ak;
    cin >> m >> k >> a1 >> ak;

    int nbK = m / k;
    int nb1 = m % k;

    int cost = nbK + nb1;

    cost -= min(ak, nbK);

    int change = min(a1, nb1);
    cost -= change;
    a1 -= change;

    cost -= min(cost, a1/k);

    cout << cost << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}

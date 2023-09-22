#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k,x;
    cin >> n >> k >> x;

    if(x < k - 1 || n < k) {
        cout << -1 << "\n";
        return;
    }

    int sum = k * (k - 1) / 2;
    n -= k;

    if(x == k) x--;
    sum += n * x;

    cout << sum << "\n";
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

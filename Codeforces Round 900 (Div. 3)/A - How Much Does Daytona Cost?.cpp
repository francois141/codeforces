#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    bool t = false;
    while(n--) {
        int tmp; cin >> tmp;
        if(tmp == k) t = true;
    }

    cout << (t ? "YES" : "NO") << "\n";
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

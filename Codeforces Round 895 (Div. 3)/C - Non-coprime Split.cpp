#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int l,r;
    cin >> l >> r;

    if(r <= 3) {
        cout << -1 << "\n";
        return;
    }

    if(l == r) {
        for(int i = 2; i <= ceil(sqrt(l));i++) {
            if(l % i == 0) {
                int o = l / i;
                cout << (i-1) * o << " " << o << "\n";
                return;
            }
        }
        cout << -1 << "\n";
    } else {
        l += (l % 2);
        if(l == 2) {
            l += 2;
        }
        cout << l/2 << " " << l/2 << "\n";
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

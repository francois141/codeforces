#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    vector<int> b(n+1);
    for(int i = 1; i <= n;i++) b[i] = a[i] ^ b[i-1];

    string s;
    cin >> s;
    s = " " + s;

    int ans1 = 0;
    int ans2 = 0;

    for(int i = 1; i <= n;i++) {
        if(s[i] == '0') {
            ans1 ^= a[i];
        } else {
            ans2 ^= a[i];
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int tp;
        cin >> tp;
        if(tp == 1) {
            int l,r;
            cin >> l >> r;
            ans1 = ans1 ^ b[l-1] ^ b[r];
            ans2 = ans2 ^ b[l-1] ^ b[r];
        } else {
            int g;
            cin >> g;
            if(g == 0) cout << ans1 << " ";
            else cout << ans2 << " ";
        }
    }

    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin >> n >> q;

    vector<int> a = vector<int>(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    auto a2 = a;

    while(q--) {
        int mod;
        cin >> mod;

        int ans = 0;

        a = a2;

        for(int k = 62; k >= 0;k--) {
            int val = 0;
            bool ok = true;
            for(auto e: a) {
                e &= (1ll << (k+1ll)) - 1ll;
                if(LLONG_MAX - val < (1ll << k) - e) {
                    ok = false;
                }
                val += max(0ll, (1ll << k) - e);
            }

            if(!ok) continue;

            if(val <= mod) {
                mod = (mod - val);
                ans |= (1ll << k);
                for(auto &e: a) {
                    if(e & (1ll << k)) {
                        e &= (1ll << k) - 1ll;
                    } else {
                        e = 0;
                    }
                }
            } else {
                for(auto &e: a) e &= (1ll << k) - 1ll;
            }

        }

        cout << ans << "\n";
    }
}

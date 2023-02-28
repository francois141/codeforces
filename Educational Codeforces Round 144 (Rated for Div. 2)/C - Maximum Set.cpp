#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353;

void solve() {
    int l,r;
    cin >> l >> r;

    int ans = 0;

    int c2 = l;
    while(c2 <= r) {
        ans++;
        c2*= 2;
    }

    int nb = 0;
    int curr = l;

    int start = 0;
    int end = 1e6;

    int p1 = pow(2,ans-1);
    int p2 = pow(2,ans-2)*3;

    int middle;
    while(start != end) {
        middle = (start + end+1) / 2;

        if(middle*p1 <= r) {
            start = middle;
        } else {
            end = middle-1;
        }
    }

    nb = (nb + (start - l + 1)) % K;

    start = 0;
    end = 1e6;

    while(start != end) {
        middle = (start + end+1) / 2;

        if(middle*p2 <= r) {
            start = middle;
        } else {
            end = middle-1;
        }
    }

    if(start >= l)
        nb = (nb + ((ans-1) * (start - l + 1)) % K) % K;

    cout << ans << " " << nb << "\n";

    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a,b,r;
    cin >> a >> b >> r;

    int answer = 0;

    int i = 62;
    for(; i >= 0;i--) {
        if((a & (1ll << i)) > (b & (1ll << i))) break;
        if((a & (1ll << i)) < (b & (1ll << i))) {
            swap(a, b);
            break;
        };
    }

    i--;
    for(; i >= 0;i--) {
        bool aSet = (a & (1ll << i));
        bool bSet = (b & (1ll << i));
        if(aSet && !bSet) {
            int test = answer | (1ll<<i);
            if(test <= r) answer = test;
        }
    }

    cout << abs((a ^ answer) - (b ^ answer)) << "\n";
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

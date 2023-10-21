#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a,b,c,k;
    cin >> a >> b >> c >> k;

    int lowA = pow(10, a-1);
    int uppA = pow(10, a);

    int lowB = pow(10, b-1);
    int uppB = pow(10, b);

    int lowC = pow(10, c-1);
    int uppC = pow(10, c);

    for(int i = lowA; i < uppA;i++) {
        int from = max(lowB, lowC - i);
        int to = min(uppB, uppC - i);
        int diff = to - from;

        if(diff >= k) {
            from--;
            cout << i << " + " << (from + k) << " = " << (i + from + k) << "\n";
            return;
        } else if(diff > 0) {
            k -= diff;
        }
    }

    cout << -1 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

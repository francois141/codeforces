#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    int v = 0;
    for(int i = 0; i < n;i++) {
        int tmp;
        cin >> tmp;
        v = v ^ tmp;
    }

    if(v == 0) {
        cout << 0 << "\n";
    } else if(n % 2 == 0) {
        cout << -1 << "\n";
    } else {
        cout << v << "\n";
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
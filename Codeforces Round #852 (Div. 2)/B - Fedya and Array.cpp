#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x,y;
    cin >> x >> y;

    cout << 2*(x - y) << "\n";

    for(int i = x; i >= y;i--) {
        cout << i << " ";
    }
    for(int i = y+1; i < x;i++) {
        cout << i << " ";
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
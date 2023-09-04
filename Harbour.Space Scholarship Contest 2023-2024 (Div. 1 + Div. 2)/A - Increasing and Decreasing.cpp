#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x,y,n;
    cin >> x >> y >> n;

    vector<int> a(n);
    a.back() = y;

    int diff = 1;
    for(int i = a.size() - 2; i >= 0;i--) {
        a[i] = a[i+1] - diff;
        diff++;
    }

    if(a[0] < x) {
        cout << -1 << "\n";
        return;
    }

    a[0] = x;

    for(auto e: a) cout << e << " ";
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

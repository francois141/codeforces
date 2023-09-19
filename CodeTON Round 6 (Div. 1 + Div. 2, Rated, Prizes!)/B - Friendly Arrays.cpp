#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < m;i++) cin >> b[i];

    int val = 0;
    for(auto e: a) val ^= e;

    int val2 = 0;
    for(auto e: b) val2 |= e;
    
    if(n % 2 == 0) {
        cout << (val & ~val2) << " " << val << "\n";
    } else {
        cout << val << " " << (val|val2) << "\n";
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

#include <bits/stdc++.h>
using namespace std;

int compute(int x, int k) {
    if(k == 0) return 0;
    if(k > x) return 1 + compute(k, k-x);

    int div = x / k;
    int ret = div + div / 2;

    if(x % k == 0 && !(div & 0x1)) {
        return ret - 1;
    } else if(x % k == 0) {
        return ret;
    }

    if(div & 0x1) {
        ret += compute(k, x % k);
    } else {
        ret += compute(x % k, k);
    }

    return ret;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n;i++) cin >> b[i];

    vector<int> c;
    for(int i = 0; i < n;i++){
        if(a[i] != 0 || b[i] != 0) {
            c.push_back(compute(a[i],b[i]) % 3);
        }
    }

    for(int i = 0; i < 3;i++) {
        int cnt = count(c.begin(), c.end(), i);
        if (cnt == c.size()) {
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";
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

#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    string x;
    cin >> x;

    string s;
    cin >> s;

    int cnt = 0;
    while (x.size() < s.size()) {
        x = x + x;
        cnt++;
    }

    for (int i = 0; i <= x.size() - s.size(); i++) {
        if (s.compare(x.substr(i, s.size())) == 0) {
            cout << cnt << "\n";
            return;
        }
    }

    while (x.size() < 2 * s.size()) {
        x = x + x;
        cnt++;
        for (int i = 0; i <= x.size() - s.size(); i++) {
            if (s.compare(x.substr(i, s.size())) == 0) {
                cout << cnt << "\n";
                return;
            }
        }
    }

    if(cnt == 0) {
        x = x + x;
        cnt++;
        for (int i = 0; i <= x.size() - s.size(); i++) {
            if (s.compare(x.substr(i, s.size())) == 0) {
                cout << cnt << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}

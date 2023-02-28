#include <bits/stdc++.h>
#define int unsigned long long int
using namespace std;

void solve() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    string s2 = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";

    for(int i = 0; i < s2.size() - k;i++) {
        if(s == s2.substr(i,k)) {
            cout << "YES" << "\n";
            return;
        }
    }

    cout << "NO" << "\n";
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

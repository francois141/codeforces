#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;

    int ans = 1;

    for(int i = 0; i < s.size();i++) {
        if(s[i] == '?') {
            if(i == 0) ans *= 9;
            else ans *= 10;
        }
    }

    if(count(s.begin(), s.end(), '0') == s.size() || s[0] == '0') {
        cout << 0 << "\n";
    } else {

        cout << ans << "\n";
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

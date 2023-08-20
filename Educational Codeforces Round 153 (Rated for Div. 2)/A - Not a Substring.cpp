#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    if(s == "()") {
        cout << "NO" << "\n";
        return;
    }

    string ans = "";

    while(n--) {
        ans += "()";
    }

    n = s.size();

    for(int i = 0; i < n;i++) {
        if(ans.substr(i, n).compare(s) == 0) {
            string ans1 = "";
            string ans2 = "";
            while(n--) {
                ans1 += '(';
                ans2 += ')';
            }

            ans = ans1 + ans2;
            break;
        }
    }

    cout << "YES" << "\n";
    cout << ans << "\n";
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    char v = *min_element(s.begin(), s.end());

    string s2 = s;
    reverse(s2.begin(), s2.end());

    int idx = n-1 - (find(s2.begin(), s2.end(), v) - s2.begin());

    char c = s[idx];
    s.erase(idx, 1);
    s = c + s;

    cout << s << "\n";
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
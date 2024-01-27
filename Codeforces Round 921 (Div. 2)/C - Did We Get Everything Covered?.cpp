#include <bits/stdc++.h>
#define int long long
using namespace std;

void fill(set<char> &s, int k) {
    for(char c = 'a'; c < 'a' + k;c++) s.insert(c);
}

void solve() {
    int n,k,m;
    cin >> n >> k >> m;

    string s;
    cin >> s;

    string ans;

    set<char> se;
    fill(se, k);

    for(char c : s) {
        if(se.find(c) != se.end()) se.erase(se.find(c));
        if(se.empty()) {
            ans += c;
            fill(se, k);
        }
    }

    if(ans.size() < n) {
        while(ans.size() < n) ans.push_back(*se.begin());
        cout << "NO" << "\n";
        cout << ans << "\n";
    } else {
        cout << "YES" << "\n";
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

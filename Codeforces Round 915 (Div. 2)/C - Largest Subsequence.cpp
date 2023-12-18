#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    multiset<char> se(s.begin(), s.end());

    vector<int> idx;
    for(int i = 0; i < n;i++) {
        if(s[i] == *se.rbegin()) idx.push_back(i);
        se.erase(se.find(s[i]));
    }

    string s2 = s;
    for(int i = 0; i < idx.size();i++) {
        s2[idx[i]] = s[idx[idx.size() - i - 1]];
    }

    if(is_sorted(s2.begin(), s2.end())) {
        int val = 0;
        while(val < idx.size() && s[idx[val]] == s[idx[0]]) {
            val++;
        }
        cout << idx.size() - val << "\n";
    } else {
        cout << -1 << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

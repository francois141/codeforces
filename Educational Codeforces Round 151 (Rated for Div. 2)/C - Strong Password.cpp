#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;

    int m;
    cin >> m;

    string l,r;
    cin >> l >> r;

    vector<queue<int>> q(10, queue<int>());

    for(int i = 0; i < s.size();i++) {
        q[s[i]-'0'].push(i);
    }

    for(int i = 0; i < 10;i++) {
        q[i].push(INT_MAX);
    }

    int pos = 0;

    for(int i = 0; i < m && pos < INT_MAX;i++) {
        int maxPos = pos;
        for(int j = l[i] - '0'; j <= r[i] - '0';j++) {
            while(q[j].front() < pos) q[j].pop();
            maxPos = max(maxPos, q[j].front());
        }
        pos = maxPos+1;
    }

    if(pos > s.size()) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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
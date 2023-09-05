#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> pre(s.size(),-1);
    vector<int> nex(s.size(),n+1);

    for(int i = 0; i < s.size();i++) {
        if(s[i] == '0') pre[i] = i;
        if(i > 0) pre[i] = max(pre[i], pre[i-1]);
    }

    for(int i = s.size()-1; i >= 0;i--) {
        if(s[i] == '1') nex[i] = i;
        if(i < s.size()-1) nex[i] = min(nex[i], nex[i+1]);
    }

    int sorted = 0;
    set<pair<int,int>> se;

    while(m--) {
        int l,r;
        cin >> l >> r;
        l--; r--;
        if(nex[l] > pre[r]) {
            sorted = 1;
        } else {
            se.insert({nex[l], pre[r]});
        }
    }

    cout << se.size() + sorted << "\n";
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

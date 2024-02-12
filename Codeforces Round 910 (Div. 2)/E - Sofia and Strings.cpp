#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;

    string s,t;
    cin >> s >> t;

    vector<vector<int>> state(26);
    for(int i = 0; i < n;i++) state[s[i] - 'a'].push_back(i);

    // Precompute allowed
    vector<int> allowed(s.size(), INT_MIN + 1);
    vector<int> last(26, INT_MIN);
    for(int i = 0; i < s.size();i++) {
        for(int j = 0; j < s[i] - 'a';j++) {
            allowed[i] = max(allowed[i], last[j] + 1);
        }
        last[s[i] - 'a'] = i;
    }

    // Go linear scan
    vector<int> positions(26, INT_MAX);
    for(int i = t.size()-1; i >= 0;i--) {
        int c = t[i] - 'a';
        for(int i = 0; i < c;i++) {
            while(!state[c].empty() && allowed[state[c].back()] >= positions[i]) state[c].pop_back();
        }

        if(state[c].empty()) {
            cout << "NO" << "\n";
            return;
        }

        positions[c] = state[c].back();
        state[c].pop_back();
    }

    cout << "YES" << "\n";
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

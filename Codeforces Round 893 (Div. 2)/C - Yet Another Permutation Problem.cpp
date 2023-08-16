#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> ans;

    set<int> s;
    for(int i = 1; i <= n;i++) s.insert(i);

    while(!s.empty()) {
        int val = *s.begin();

        while(val <= n) {
            ans.push_back(val);
            s.erase(s.find(val));
            val *= 2;
        }
    }

    for(auto e: ans) cout << e << " ";
    cout << "\n";
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

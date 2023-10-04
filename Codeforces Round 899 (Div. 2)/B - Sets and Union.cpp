#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    multiset<int> total;
    vector<set<int>> sets(n);
    
    for(int i = 0; i < n;i++) {
        int k; cin >> k;
        while(k--) {
            int tmp; cin >> tmp;
            total.insert(tmp);
            sets[i].insert(tmp);
        }
    }

    int ans = 0;

    for(auto value: total) {
        auto tmp = total;
        int cnt = n;
        for(int i = 0; i < n;i++) {
            if(sets[i].find(value) != sets[i].end()) {
                cnt--;
                for(auto e: sets[i]) {
                    tmp.erase(tmp.find(e));
                }
            }
        }

        set<int> z(tmp.begin(), tmp.end());
        if(z.size() > ans) ans = z.size();
    }

    cout << ans << "\n";
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

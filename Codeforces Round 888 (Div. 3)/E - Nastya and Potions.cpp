#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    // Can imrpo
    vector<bool> ok(n+1, false);

    vector<int> costs(n+1);
    for(int i = 1; i <= n;i++) cin >> costs[i];

    for(int i = 0; i < k;i++) {
        int idx; cin >> idx;
        costs[idx] = 0;
        ok[idx] = true;
    }

    vector<int> c2(n+1, 0);
    vector<vector<int>> dep(n+1, vector<int>());
    set<pair<int,int>> s;

    for(int i = 1; i <= n;i++) {
        int size; cin >> size;
        if(size == 0) {
            c2[i] = costs[i];
            ok[i] = true;
        } else {
            for(int j = 0; j < size; j++) {
                int idx; cin >> idx;
                c2[i] += costs[idx];
                dep[idx].push_back(i);
            }
            s.insert({c2[i],i});
        }
    }

    while(!s.empty()) {
        auto p = *s.begin();
        s.erase(s.begin());

        ok[p.second] = true;
        if(c2[p.second] < costs[p.second]) {
            int diff = costs[p.second] - c2[p.second];
            costs[p.second] = c2[p.second];

            for(auto d: dep[p.second]) {
                if(ok[d]) continue;
                auto p2 = s.erase(s.find({c2[d], d}));
                c2[d] -= diff;
                s.insert({c2[d], d});
            }
        }
    }

    for(int i = 1; i <= n;i++) {
        cout << costs[i] << " ";
    } cout << endl;
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

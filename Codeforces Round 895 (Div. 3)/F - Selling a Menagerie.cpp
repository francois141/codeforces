#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    vector<int> c(n+1);

    for(int i = 1; i <= n;i++) cin >> a[i];
    for(int i = 1; i <= n;i++) cin >> c[i];

    vector<int> fear(n+1);
    for(auto e: a) {
        fear[e]++;
    }

    set<int> s;
    for(int i = 1; i <= n;i++) {
        if(fear[i] == 0) {
            s.insert(i);
        }
    }

    vector<int> ans;

    while(!s.empty()) {
        auto idx = *s.begin();
        s.erase(s.begin());
        ans.push_back(idx);
        fear[a[idx]]--;
        if(fear[a[idx]] == 0) {
            s.insert(a[idx]);
        }
    }

    set<pair<int,int>> s2;
    for(int i = 1; i <= n;i++) {
        if(fear[i] > 0) {
            s2.insert({c[i], a[i]});
        }
    }

    while(!s2.empty()) {
        auto it = *s2.begin();
        s2.erase(s2.begin());

        if(fear[it.second] == 0) continue;
        fear[it.second]--;

        s.clear();
        s.insert(it.second);

        while(!s.empty()) {
            auto idx = *s.begin();
            s.erase(s.begin());
            ans.push_back(idx);
            fear[a[idx]]--;
            if(fear[a[idx]] == 0) {
                s.insert(a[idx]);
            }
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k,x;
    cin >> n >> k >> x;

    set<int> s;
    for(int i = 0; i <= n;i++) s.insert(i);

    vector<vector<int>> ans;
    vector<int> r;

    int rest = 0;

    while(!s.empty()) {
        int val = (*s.begin());
        s.erase(s.begin());
        auto it = s.find(val ^ x);
        if(it != s.end()) {
            s.erase(it);
            if(val == 0) ans.push_back({x});
            else ans.push_back({val, val^x});
        } else if(val != 0){
            rest ^= val;
            r.push_back(val);
        }
    }

    if(rest == x) {
        ans.push_back(r);
        r.clear();
        rest = 0;
    }

    if(rest != 0 || ans.size() < k || ans.size() % 2 != k % 2) {
        cout << "NO" << "\n";
        return;
    }

    if(r.size() != 0) copy(r.begin(), r.end(), back_inserter(ans[0]));

    while(ans.size() > k) {
        copy(ans[ans.size()-1].begin(), ans[ans.size()-1].end(), back_inserter(ans[0]));
        copy(ans[ans.size()-2].begin(), ans[ans.size()-2].end(), back_inserter(ans[0]));
        ans.pop_back();
        ans.pop_back();
    }

    cout << "YES" << "\n";
    for(auto e: ans) {
        cout << e.size() << " ";
        for(auto e2: e) cout << e2 << " ";
        cout << "\n";
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

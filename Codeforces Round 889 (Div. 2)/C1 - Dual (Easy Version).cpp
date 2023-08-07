#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int max_val = *max_element(a.begin(), a.end());
    int min_val = *min_element(a.begin(), a.end());

    vector<pair<int,int>> ans;

    if(max_val > 0) {
        int idx = max_element(a.begin(), a.end()) - a.begin();
        for(int i = 0; i < 6;i++) ans.push_back({idx, idx});
        ans.push_back({0, idx});
        for(int i = 0; i < n-1;i++) {
            ans.push_back({i+1,i});
            ans.push_back({i+1,i});
        }
    } else if(min_val < 0) {
        int idx = min_element(a.begin(), a.end()) - a.begin();
        for(int i = 0; i < 6;i++) ans.push_back({idx, idx});
        ans.push_back({n-1, idx});
        for(int i = n-1; i > 0;i--) {
            ans.push_back({i-1,i});
            ans.push_back({i-1,i});
        }
    }

    cout << ans.size() << "\n";
    for(auto p: ans) {
        cout << p.first+1 << " " << p.second+1 << "\n";
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
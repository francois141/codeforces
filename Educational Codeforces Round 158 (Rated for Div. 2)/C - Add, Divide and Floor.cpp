#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int v1 = *min_element(a.begin(),a.end());
    int v2 = *max_element(a.begin(), a.end());

    vector<int> ans;
    while(v1 != v2) {
        if(v2 & 0x1) ans.push_back(0);
        else ans.push_back(v1 & 0x1);
        v1 = (v1 + ans.back()) / 2;
        v2 /= 2;
    }

    cout << ans.size() << "\n";

    if(ans.size() > 0 && ans.size() <= n) {
        for(auto e: ans) cout << e << " ";
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
}

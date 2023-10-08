#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> shift(vector<int> value, int f) {
    auto ans = value;
    for(int i = 0; i < value.size();i++) {
        ans[(i+f) % value.size()] = value[i];
    }

    return ans;
}

void solve() {
    int n,m;
    cin >> n >> m;

    if(m == 1)  {
        cout << 0 << "\n";
        while(n--) {
            cout << 0 << "\n";
        }
        return;
    }

    vector<vector<int>> ans(n, vector<int>(m, 0));

    int i = 0;
    for(; i < min(n,m-1);i++) {
        iota(ans[i].begin(), ans[i].end(), 0);
        ans[i] = shift(ans[i], i+1);
    }

    for(; i < n;i++) {
        iota(ans[i].begin(), ans[i].end(), 0);
        ans[i] = shift(ans[i], 1);
    }

    cout << min(n+1, m) << "\n";
    for(auto e: ans) {
        for(auto e2: e) {
            cout << e2 << " ";
        }
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

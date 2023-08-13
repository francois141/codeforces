#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()  {
    int n;
    cin >> n;

    vector<vector<int>> values(n);
    for(int i = 0; i < n;i++) {
        int m;
        cin >> m;

        values[i] = vector<int>(m);
        for(int j = 0; j < m;j++) cin >> values[i][j];
    }

    vector<int> v1;
    vector<int> v2;

    for(int i = 0; i < n;i++) {
        sort(values[i].begin(), values[i].end());
        v1.push_back(values[i][0]);
        v2.push_back(values[i][1]);
    }

    int tmp1 = *min_element(v2.begin(), v2.end());
    int tmp2 = *min_element(v1.begin(), v1.end());

    int ans = accumulate(v2.begin(), v2.end(), 0ll) - tmp1 + tmp2;

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

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> matrix(n);
    for(int i = 0; i < n;i++) cin >> matrix[i];

    int ans = 0;

    for(int i = 0; i < n/2;i++) {
        for(int j = 0; j < n/2;j++) {
            vector<int> values = {matrix[i][j], matrix[n-i-1][n-j-1], matrix[n-j-1][i], matrix[j][n-i-1]};
            int m = *max_element(values.begin(), values.end());
            for(auto e: values) ans += m - e;
        }
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
}

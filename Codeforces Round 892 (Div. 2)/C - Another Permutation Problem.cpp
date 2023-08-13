#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int ans = 0;

        int n;
        cin >> n;

        vector<int> v(n);
        iota(v.begin(), v.end(), 1);

        for(int i = 0; i <= n;i++) {
            int tmp = 0;
            int m = 0;
            auto v2 = v;
            reverse(v2.begin() + i, v2.end());
            for(int j = 0; j < n;j++) {
                tmp += v[j] * v2[j];
                m = max(m, v[j]*v2[j]);
            }

            ans = max(ans, tmp-m);
        }

        cout << ans << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; // or 1e9 + 7;

inline int add(int a,int b) {return ((a%K)+(b%K)) % K;}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int ans = 0;

    for(int i = 0; i <= 30;i++) {
        vector<int> curr = {1,0};
        vector<int> total = {1,0};
        int idx = 0;
        for(auto e: a) {
            idx ^= (e >> i) & 0x1;
            ans = add(ans, total[1-idx]<<i);
            curr[idx]++;
            total[0] = add(total[0],curr[0]);
            total[1] = add(total[1],curr[1]);
        }
    }

    cout << ans << "\n";

    return 0;
}

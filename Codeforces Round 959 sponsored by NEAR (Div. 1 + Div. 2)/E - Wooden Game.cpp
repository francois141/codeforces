#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

void solve() {
    int k;
    cin >> k;

    vector<int> a(31, 0);   

    while(k--) {
        int n;
        cin >> n;

        int tmp;
        for(int i = 0; i < n-1;i++) cin >> tmp;

        for(int i = 30; i >= 0;i--) {
            if((n >> i) & 0x1) {
                if(a[i]) {
                    for(int j = i-1; j >= 0;j--) a[j] = 1;
                    break;
                } else {
                    a[i] = 1;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 31;i++) {
        ans += (1 << i) * min(a[i], 1);
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

    return 0;
}

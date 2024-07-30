#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    vector<int> factor(n);
    for(int i = 1; i < n;i++) {
        if(a[i] == 1 && a[i-1] != 1) {
            cout << -1 << "\n";
            return;
        } 

        int value = a[i-1];
        if(a[i-1] == 1) continue;

        if(value < a[i]) {
            while(value <= a[i]) {
                factor[i]--;
                value *= value;
            }
            factor[i]++;
        } else {
            value = a[i];
            while(value < a[i-1]) {
                factor[i]++;
                value *= value;
            }
        }

    }

    int ans = 0;
    int prev = 0;

    for(int i = 1; i < n;i++) {
        prev = max(0ll, prev + factor[i]);
        ans += prev;
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

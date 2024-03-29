#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int cnt = 0;
    for(int i = 1; i < n;i++) {
        if(a[i-1] >= a[i]) {
            cnt++;
        }
    }

    int ans = cnt;
    int cnt2 = 0;

    for(int i = 0; i < n;i++) {
        ans = min(ans, cnt + cnt2 + 1);

        if(i +1 < n && a[i] >= a[i+1]) cnt--;
        if(i > 0 && a[i-1] <= a[i]) cnt2++;
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,p;
    cin >> n >> p;

    vector<pair<int,int>> a(n);
    for(int i = 0; i < n;i++) cin >> a[i].first;
    for(int i = 0; i < n;i++) cin >> a[i].second;

    sort(a.begin(), a.end(), [](auto e1, auto e2) {
        return e1.second < e2.second;
    });

    int ans = p;
    int cnt = n-1;
    int idx = 0;

    while(cnt > 0) {
        cnt--;
        ans += min(p, a[idx].second);
        a[idx].first--;
        if(a[idx].first == 0) idx++;
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

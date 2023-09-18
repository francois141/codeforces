#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<pair<int,int>> a(n+1, make_pair(0,0));
    for(int i = 1; i <= n;i++) cin >> a[i].first;
    for(int i = 1; i <= n;i++) a[i].second = i;

    int k; cin >> k;

    sort(a.begin(), a.end(), [](auto e1, auto e2) {
        return e1.first < e2.first || (e1.first == e2.first && e1.second > e2.second);
    });

    vector<int> ans(n+1);
    int last = 0;
    int lastVal = 0;
    int lastAns = INT_MAX;

    for(int i = 1; i < a.size();i++) {
        if(a[i].second < last) continue;

        int delta = a[i].first - lastVal;
        int diff = min(k / delta, lastAns);

        k -= diff*delta;
        lastVal = a[i].first;

        while(last <= a[i].second) {
            ans[last] = diff;
            last++;
        }

        lastAns = ans[last-1];
    }

    for(int i = 1; i <= n;i++) cout << ans[i] << " ";
    cout << "\n";
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

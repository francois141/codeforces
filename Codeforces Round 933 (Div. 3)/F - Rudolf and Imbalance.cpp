#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m,k;
    cin >> n >> m >> k;

    vector<int> a(n);
    vector<int> d(m);
    vector<int> f(k);

    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < m;i++) cin >> d[i];
    for(int i = 0; i < k;i++) cin >> f[i];

    sort(d.begin(), d.end());
    sort(f.begin(), f.end());

    int idx = 0;
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < n-1;i++) {
        if(a[i+1] - a[i] > largest) {
            idx = i;
            secondLargest = largest;
            largest = a[i+1] - a[i];
        } else if(a[i+1] - a[i] > secondLargest) {
            secondLargest = a[i+1] - a[i];
        }
    }

    int ans = largest;

    int reach = (a[idx+1] + a[idx]) / 2;
    for(int i = 0; i < m;i++) {
        auto it = lower_bound(f.begin(), f.end(), reach - d[i]);
        if(it != f.end()) {
            int val = max({secondLargest, (d[i] + *it) - a[idx], a[idx+1] - (d[i] + *it)});
            ans = min(ans, val);
        }
        if(it != f.begin()) {
            it = prev(it);
            int val = max({secondLargest, (d[i] + *it) - a[idx], a[idx+1] - (d[i] + *it)});
            ans = min(ans, val);
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

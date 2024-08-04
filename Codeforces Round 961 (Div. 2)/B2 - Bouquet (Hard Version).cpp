#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <assert.h>
#include <cmath>

using namespace std;
#define int long long

void solve() {
    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> a(n);
    for(int i = 0; i < n;i++) cin >> a[i].first;
    for(int i = 0; i < n;i++) cin >> a[i].second;

    sort(a.begin(), a.end());

    int ans = 0;
    
    for(int i = 0; i < n;i++) {
        ans = max(ans, min((m/a[i].first),a[i].second) * a[i].first);
    }

    for(int i = 0; i < n-1;i++) {
        if(a[i].first+1 != a[i+1].first) continue;

        int val = m;
        int best = 0;

        int f1 =  min((val/a[i].first),a[i].second);
        val -= f1 * a[i].first;

        int f2 =  min((val/a[i+1].first),a[i+1].second);
        val -= f2 * a[i+1].first;
        
        val -= min({f1, a[i+1].second - f2, val});

        ans = max(ans, m - val);
    }


    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

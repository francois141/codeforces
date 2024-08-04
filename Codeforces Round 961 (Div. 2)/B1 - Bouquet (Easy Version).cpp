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

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    int end = 0;
    int curr = 0;

    for(int start = 0; start < n; start++) {
        curr += a[start];
        while(curr > m || a[start] - a[end] > 1) {
            if(end == start) break;
            curr -= a[end];
            end++;
        }

        if(curr <= m)
            ans = max(ans,curr);
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

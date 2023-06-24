#include <bits/stdc++.h>
using namespace std;

struct range {
    int min;
    int max;
    int currMin;
    int currMax;
};

void solve() {
    int n;
    cin >> n;

    vector<range> ranges(n+2);
    ranges[1] = range{0,1,0,1};

    int pos = 1;
    for(int i = 0; i < n;i++) {
        char e;
        cin >> e;
        if(e == '+') {
            int from, dis;
            cin >> from >> dis;
            range r = ranges[from];
            r.currMin = min(0, r.currMin + dis);
            r.currMax = max(0, r.currMax + dis);
            r.min = min(r.min, r.currMin);
            r.max = max(r.max, r.currMax);
            ranges[++pos] = r;
        } else {
            int u,v,k;
            cin >> u >> v >> k;
            if(ranges[v].min <= k && k <= ranges[v].max) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }
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
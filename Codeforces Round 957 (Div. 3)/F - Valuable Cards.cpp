#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
#define int long long


void solve() {
    int n,x;
    cin >> n >> x;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int ans = 1;

    set<int> s;
    s.insert(1);

    for(auto e: a) {
        auto s2 = s;
        for(auto e2: s) {
            if(e * e2 <= x && x % (e * e2) == 0) {
                s2.insert(e * e2);
            }
        }
        s = s2;

        if(s.find(x) != s.end()) {
            ans++;
            s.clear();
            s.insert(1);
            s.insert(e);
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

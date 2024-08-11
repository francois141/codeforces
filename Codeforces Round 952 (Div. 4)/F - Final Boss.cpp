#include <bits/stdc++.h>
#define int long long
using namespace std;

struct entry {
    int curr;
    int a;
    int c;
    bool operator<(const entry& other) const {
        return curr < other.curr;
    }
};

void solve() {
    int h,n;
    cin >> h >> n;

    vector<entry> a(n, {0,0,0});
    for(int i = 0; i < n; i++) cin >> a[i].a;
    for(int i = 0; i < n; i++) cin >> a[i].c;

    multiset<entry> s(a.begin(), a.end());

    int ans = 0;
    while(h > 0) {
        auto e = *s.begin();
        s.erase(s.begin());

        ans = max(ans, e.curr);
        h -= e.a;
        e.curr += e.c;

        s.insert(e);
    }

    cout << ans+1 << "\n";
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

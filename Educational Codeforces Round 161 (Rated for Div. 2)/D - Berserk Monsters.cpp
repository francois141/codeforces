#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+2);
    vector<int> d(n+2);
    a[0] = a.back() = 0;
    d[0] = d.back() = LLONG_MAX;

    for(int i = 1; i <= n;i++) cin >> a[i];
    for(int i = 1; i <= n;i++) cin >> d[i];

    set<int> s, marked;

    for(int i = 0; i <= n+1;i++) s.insert(i);

    for(int i = 1; i <= n;i++) {
        if (a[i - 1] + a[i + 1] > d[i]) marked.insert(i);
    }

    vector<int> ans(n);
    set<int> tmp;

    for(int i = 0; i < n;i++) {
        set<int> toErase;

        for(auto e: marked) {
            if(s.find(e) == s.end()) continue;
            if (a[*prev(s.find(e))] + a[*next(s.find(e))] > d[e]) {
                ans[i]++;
                tmp.insert(*prev(s.find(e)));
                tmp.insert(*next(s.find(e)));
                toErase.insert(e);
            }
        }

        for(auto e: toErase) s.erase(s.find(e));

        marked = tmp;
        tmp.clear();
    }

    for(auto e: ans) cout << e << " ";
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

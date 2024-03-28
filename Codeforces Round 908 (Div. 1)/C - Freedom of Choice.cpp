#include <bits/stdc++.h>
#define int long long
using namespace std;

struct entry {
  int n,l,r;
};

void solve() {
    int m;
    cin >> m;

    vector<entry> entries(m);
    vector<vector<int>> a(m);
    vector<vector<int>> c(m);

    int somme = 0;
    int min_s = 0;
    int max_s = 0;

    map<int,int> mp;
    map<int,int> mp_fix;

    for(int i = 0; i < m;i++) {
        cin >> entries[i].n >> entries[i].l >> entries[i].r;
        int n = entries[i].n;
        int r = entries[i].r;
        int l = entries[i].l;

        a[i] = vector<int>(n);
        c[i] = vector<int>(n);

        for(int j = 0; j < n;j++) cin >> a[i][j];
        for(int j = 0; j < n;j++) cin >> c[i][j];

        int s_c = accumulate(c[i].begin(), c[i].end(), 0ll);

        for(int j = 0; j < n;j++) {
            int tmp = s_c - c[i][j];
            mp[a[i][j]] += max(0ll, min(r - tmp, r - l));
            mp_fix[a[i][j]] += max(0ll, l - tmp);
        }
    }

    for(auto e: entries) {
        somme += e.n;
        min_s += e.l;
        max_s += e.r;
    }

    int ans = LLONG_MAX;

    for(int i = min_s; i <= min(min_s + somme, max_s);i++) {
        int price = max(i - (max_s - mp[i]),0ll);
        ans = min(ans, price + mp_fix[i]);
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

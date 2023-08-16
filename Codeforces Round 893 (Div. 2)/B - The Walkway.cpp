#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m,d;
    cin >> n >> m >> d;

    set<int> sellers;
    for(int i = 0; i < m;i++) {
        int tmp;
        cin >> tmp;
        sellers.insert(tmp);
    }

    sellers.insert(1);

    int ans = 0;
    int prev = 0;

    for(auto s: sellers) {
        ans += ceil((s - prev) / (double)d);
        prev = s;
    }

    ans += floor((n - prev) / (double)d);

    vector<int> sel;
    for(auto e: sellers) {
        sel.push_back(e);
    }

    int cnt = 0;
    for(int i = 2; i < sel.size();i++) {
        int c1 = ceil((sel[i] - sel[i-2]) / (double)d);
        int c21 = ceil((sel[i] - sel[i-1]) / (double)d);
        int c22 = ceil((sel[i-1] - sel[i-2]) / (double)d);
        if(c1 < c21 + c22) cnt++;
    }

    {
        int i = sel.size();
        int c1 = floor((n - sel[i-2]) / (double)d);
        int c21 = floor((n - sel[i-1]) / (double)d);
        int c22 = ceil((sel[i-1] - sel[i-2]) / (double)d);
        if(c1 < c21 + c22) cnt++;
    }

    if(cnt > 0) {
        ans--;
    } else {
        cnt = m;
    }

    cout << ans << " " << cnt << "\n";
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

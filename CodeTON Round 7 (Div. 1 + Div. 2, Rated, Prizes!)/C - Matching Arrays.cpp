#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,x;
    cin >> n >> x;

    vector<pair<int,int>> a(n);
    for(int i = 0; i < n;i++) cin >> a[i].first;
    for(int i = 0; i < n;i++) a[i].second = i;

    vector<pair<int,int>> b(n);
    for(int i = 0; i < n;i++) cin >> b[i].first;
    for(int i = 0; i < n;i++) b[i].second = i;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i = 0; i < x;i++) {
        if(b[i].first >= a[n - x + i].first) {
            cout << "NO" << "\n";
            return;
        }
    }

    for(int i = x;i < n;i++) {
        if(a[i - x].first > b[i].first) {
            cout << "NO" << "\n";
            return;
        }
    }

    vector<int> ans(n);

    int i = 0;
    for(; i < n-x;i++) ans[a[i].second] = b[x + i].first;
    for(; i < n;i++) ans[a[i].second] = b[i - (n-x)].first;

    cout << "YES" << "\n";
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
}

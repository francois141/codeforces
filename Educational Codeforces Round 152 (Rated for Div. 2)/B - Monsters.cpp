#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    vector<pair<int,int>> a(n);
    for(int i = 0; i < n;i++) {
        cin >> a[i].first;
        a[i].first += k;
        a[i].first %= k;
        a[i].second = i+1;
    }

    sort(a.begin(), a.end());

    for(auto p : a) {
        if(p.first == 0) {
            cout << p.second << " ";
        }
    }

    sort(a.begin(), a.end(), [](auto e1, auto e2) {
        return e1.first > e2.first || (e1.first == e2.first && e1.second < e2.second);
    });

    for(auto p : a) {
        if(p.first != 0) {
            cout << p.second << " ";
        }
    }

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

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct eq {
    int a;
    int b;
    int c;
};

void solve() {
    int n,m;
    cin >> n >> m;

    vector<int> k(n);
    for(int i = 0; i < n;i++) {
        cin >> k[i];
    }

    sort(k.begin(), k.end());

    vector<eq> eqs;
    for(int i = 0; i < m;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        eqs.push_back({a,b,c});
    }

    for(auto e : eqs) {
        int m1 = floor(e.b - 2*sqrt(e.a*e.c)) + 1;
        int m2 = ceil(e.b + 2*sqrt(e.a*e.c));

        auto it = lower_bound(k.begin(), k.end(), m1);
        if(it != k.end() && *it < m2) {
            cout << "YES" << "\n";
            cout << *it << "\n";
        } else {
            cout << "NO" << "\n";
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
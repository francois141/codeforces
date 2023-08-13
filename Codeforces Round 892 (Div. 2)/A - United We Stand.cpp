#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()  {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    vector<int> v1;
    vector<int> v2;

    int max_elem = *max_element(a.begin(), a.end());

    for(auto e : a) {
        if(e == max_elem) {
            v2.push_back(e);
        } else  {
            v1.push_back(e);
        }
    }

    if(v1.size() == 0) {
        cout << -1 << "\n";
    } else {
        cout << v1.size() << " " << v2.size() << "\n";
        for(auto e: v1) cout << e << " ";
        cout << "\n";
        for(auto e: v2) cout << e << " ";
        cout << "\n";
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    vector<int> ans;
    vector<int> ans2;

    int cliques = ceil(n/(double)k);

    int base = 0;
    while(base < n) {
        vector<int> tmp;
        for(int i = 0; i < k;i++) {
            if(base + i < n) {
                tmp.push_back(base+i);
                ans2.push_back(base/k);
            }
        }

        reverse(tmp.begin(), tmp.end());
        rotate(tmp.rbegin(), tmp.rbegin() + (tmp.size() / 2), tmp.rend());

        copy(tmp.begin(), tmp.end(), back_inserter(ans));
        base += k;
    }

    for(auto e: ans) cout << e+1 << " ";
    cout << "\n";

    cout << cliques << "\n";

    for(auto e: ans2) cout << e+1 << " ";
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

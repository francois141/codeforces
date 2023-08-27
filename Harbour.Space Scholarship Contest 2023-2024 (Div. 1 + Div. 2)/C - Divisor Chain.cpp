#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> ans;
    ans.push_back(n);

    int idx = 0;
    while(__builtin_popcount(n) > 1)  {
        int mask = (1 << idx);
        if(n & mask) {
            n -= mask;
            ans.push_back(n);
        }
        idx++;
    }

    idx = 31;
    while(n > 1) {
        int mask = (1 << idx);
        if(n & mask) {
            n -= mask/2;
            ans.push_back(n);
        }
        idx--;
    }

    cout << ans.size() << "\n";
    for(auto e: ans) cout << e << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

int getLargest(int x) {
    int cnt = 0;
    while(x > 0) {
        x /= 2;
        cnt++;
    }
    return cnt;
}

void solve() {
    int x;
    cin >> x;

    int val = getLargest(x) - 1;

    int curr1 = 200;
    int curr2 = 0;

    vector<int> ans;

    ans.push_back(curr2--);
    for(int i = val-1; i >= 0;i--) {
        if(x & (1ll << i)) ans.push_back(curr2--);
        if(i != 0) ans.push_back(curr1++);
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

    while(t--)
        solve();

    return 0;
}

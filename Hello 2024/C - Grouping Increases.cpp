#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    int ans = 0;

    pair<int,int> curr = make_pair(INT_MAX, INT_MAX);

    for(int i = 0; i < n;i++) {
        int x;
        cin >> x;

        if(x <= curr.first) curr.first = x;
        else if(x <= curr.second) curr.second = x;
        else {
            curr.first = x;
            ans++;
        }

        if(curr.second < curr.first) swap(curr.first, curr.second);
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

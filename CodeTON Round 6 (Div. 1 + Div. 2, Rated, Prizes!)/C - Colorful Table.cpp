#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    set<pair<int,int>> s;
    for(int i = 0; i < n;i++) {
        int tmp;
        cin >> tmp;
        s.insert({tmp, i});
    }

    vector<int> ans(k+1);

    int left = INT_MAX;
    int right = INT_MIN;
    int curr = k;

    while(curr > 0) {
        if(s.empty() || s.rbegin()->first < curr) {
            curr--;
            continue;
        }

        while(!s.empty() && s.rbegin()->first == curr) {
            left = min(left, s.rbegin()->second);
            right = max(right, s.rbegin()->second);
            s.erase(prev(s.end()));
        }

        ans[curr] = max(0ll, 2*(right - left + 1));
        curr--;
    }

    for(int i = 1; i <= k;i++) cout << ans[i] << " ";
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

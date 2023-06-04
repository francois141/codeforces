#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> upp(26);
    vector<int> low(26);

    for(auto c: s) {
        if(islower(c)) {
            low[c-'a']++;
        } else {
            upp[c - 'A']++;
        }
    }

    int ans = 0;
    for(int i = 0; i < 26;i++) {
        ans += min(upp[i],low[i]);
        int diff = max(upp[i],low[i]) - min(upp[i],low[i]);
        while(k > 0 && diff >= 2) {
            diff -= 2;
            k--;
            ans++;
        }
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
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k;

void merge(vector<vector<int>>& dp, int idx) {
    vector<int> out;
    merge(dp[idx].rbegin(), dp[idx].rend(), dp[idx-1].rbegin(), dp[idx-1].rend(), back_inserter(out));
    reverse(out.begin(), out.end());
    for(int i = 0; i < k;i++) dp[idx][i] = out[i];
}

void solve() {
    cin >> n >> k;

    vector<vector<int>> a(n+1, vector<int>(n+1));
    for(int i = 1; i <= n;i++) {
        for(int j = i; j <= n; j++) cin >> a[i][j];
    }

    vector<vector<int>> dp(n+1, vector<int>(k, INT_MIN));
    dp[0][0] = 0;

    for(int i = 1; i <= n;i++) {
        set<pair<int,int>> s;
        vector<int> values(n+1);
        for(int j = 1; j <= i;j++) {
            s.insert({dp[max(j-2, 0ll)][0] + a[j][i], j});
        }   

        int idx = 0;
        while(!s.empty() && idx < k) {
            auto pair = *s.rbegin();
            s.erase(prev(s.end()));
            dp[i][idx++] = pair.first;
            values[pair.second]++;
            s.insert({dp[max(pair.second-2,0ll)][values[pair.second]] + a[pair.second][i],pair.second});
        }

        merge(dp, i);
    } 

    for(auto e: dp.back()) cout << e << " ";
    cout << "\n";

    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

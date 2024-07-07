#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
#define int long long

vector<vector<int>> graph;
vector<int> a;

int ans;

int sizeMax = 5e3 + 1;

vector<int> dfs(int curr) {
    vector<int> dp(sizeMax);
    int sum = 0;

    if(graph[curr].size() == 0) {
        dp[1] = INT_MAX;
        return dp;
    }

    for(auto e: graph[curr]) {
        // Update dp values
        auto ret = dfs(e);
        for(int i = 1; i < sizeMax;i++) dp[i] += ret[i];
        // Sum missing
        sum += a[e];
    }

    // Get diff
    int diff = a[curr] - sum;

    int idx = 1;
    while(diff > 0) {
        int rem = min(diff, dp[idx]);
        dp[idx] -= rem;
        diff -= rem;
        ans += idx * rem;
        idx++;
    }

    for(int i = sizeMax-2; i >= 0;i--) {
        dp[i+1] = dp[i]; 
    }

    diff = -diff;
    dp[1] += diff;

    return dp;
}

void solve() {
    int n;
    cin >> n;

    a = vector<int>(n+1);
    for(int i = 1; i <=n; i++) cin >> a[i];

    graph = vector<vector<int>>(n+1);

    for(int i = 2; i <= n;i++) {
        int x;
        cin >> x;
        graph[x].push_back(i);
    }

    ans = 0;

    dfs(1);

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

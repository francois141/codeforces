#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> graph;
vector<int> dp;
vector<int> a;
int ans;

int dfs(int curr, int p) {

    vector<int> values;
    for(auto e: graph[curr]) {
        if(e == p) continue;

        values.push_back(dfs(e, curr));
    }

    sort(values.rbegin(), values.rend());

    int ret = a[curr];
    ans = max(ans, a[curr]);
    
    if(values.empty())  {
        ans = max(ans, a[curr]);
        ret = max(ret, a[curr]);
    } 
    
    if(values.size() >= 1) {
        ans = max(ans, a[curr] + values[0]);
        ret = max(ret, values[0]);
    } 
    
    if(values.size() >= 2) {
        ans = max(ans, values[0] + values[1]);
        ret = max(ret, values[0] + values[1] + a[curr]);
    }

    if(values.size() >= 3) {
        int s = 0;
        for(int i = 0; i < values.size();i++) {
            if(i < 3) s += values[i];
            else s += max(0ll, values[i]);
        }
        s += a[curr];
        ans = max(ans, s);
        ret = max(ret, s);
    }

    dp[curr] = ret;

    return ret;
}

void solve() {
    int n;
    cin >> n;

    a = vector<int>(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    graph = vector<vector<int>>(n+1);
    for(int i = 0; i < n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dp = vector<int>(n+1);

    ans = 0;

    dfs(1,0);


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

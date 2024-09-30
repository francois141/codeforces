#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> graph;
vector<int> values;
vector<int> depth;

int pre(int curr, int d, int p) {
    for(auto e: graph[curr]) {
        if(e != p) {
            depth[curr] = max(depth[curr], pre(e, d+1, curr) + 1);
        }
    }

    return depth[curr];
}

void dfs(int curr, int d, int contrib, int p) {
    contrib++;
    values[d] += contrib;

    int idx = -1;
    int maxVal = -1;

    for(auto e: graph[curr]) {
        if(e != p) {
            if(depth[e] > maxVal) {
                maxVal = depth[e];
                idx = e;
            }
        }
    }

    for(auto e: graph[curr]) {
        if(e != p) {
            if(e == idx) {
                dfs(e, d+1, contrib, curr);
            } else {
                dfs(e, d+1, 0, curr);
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    graph = vector<vector<int>>(n+1);
    for(int i = 0; i < n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    values = vector<int>(n+1);
    depth = vector<int>(n+1);

    for(auto e: graph[1]) {
        pre(e, 1, 1);
    }

    for(auto e: graph[1]) {
        dfs(e, 1, 0, 1);
    }

    int ans = n-1;
    for(auto e: values) ans = min(ans, n-1 - e);
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

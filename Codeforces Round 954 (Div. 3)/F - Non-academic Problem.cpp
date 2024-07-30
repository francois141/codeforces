#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>
#define int long long
using namespace std;


int n,m; 
vector<vector<int>> adj; 

vector<bool> visited;
vector<int> tin, low;
int timer;

int best;

void IS_BRIDGE(int size) {
    best = max(best, size * ((n-1) - size));
}


int dfs(int v, int p = -1) {
    int size = 1;

    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            int current = dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(current);
            size += current;
        }
    }

    return size;
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 1; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void solve() {
    cin >> n >> m;
    n++;
    adj = vector<vector<int>>(n);
    for(int i = 0; i < m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    best = 0;

    find_bridges();

    cout << (n-1) * (n - 2) / 2 - best << "\n";
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

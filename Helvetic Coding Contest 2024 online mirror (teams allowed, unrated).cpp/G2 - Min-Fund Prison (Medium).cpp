#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> graph;

int n,m,c;

bitset<301> b1;
bitset<301> b2;
vector<bool> visited;
vector<int> tin, low;
int timer;

int dfs(int v, int p = -1) {
    int acc = 1;
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (int to : graph[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            int tmp = dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                auto btmp = b1;
                b2 |= btmp << tmp;
            }
            acc += tmp;
        }
    }
    return acc;
}

int find_bridges() {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            cnt++;
            int tmp = dfs(i);
            b1 |= (b1 << tmp);
            b2 |= (b2 << tmp);
        }
    }
    return cnt;
}

void solve()  {
    cin >> n >> m >> c;

    graph = vector<vector<int>>(n+1);
    for(int i = 0; i < m;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    b1.reset();
    b2.reset();
    b1[0] = true;

    int cnt = find_bridges();

    int best = INT_MAX;
    for(int i = 0; i <= 300;i++) {
        if((b1[i] || b2[i]) && abs(n/2 - i) < abs(n/2-best)) {
            best = i;
        }
    }

    if(cnt == 1 && b2.none()) {
        cout << -1 << "\n";
    } else {
        cout << best*best + (n-best)*(n-best) + (cnt-1) * c << "\n";
    }
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

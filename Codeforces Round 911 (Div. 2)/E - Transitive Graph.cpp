#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

vector<int> roots;
vector<int> root_nodes;
vector<vector<int>> adj_scc;

vector<pair<int,int>> root_size_weight;
vector<pair<int,int>> dp;

void dfs1(int v) {
    used[v] = true;

    for (auto u : adj[v])
        if (!used[u])
            dfs1(u);

    order.push_back(v);
}

void dfs2(int v) {
    used[v] = true;
    component.push_back(v);

    for (auto u : adj_rev[v])
        if (!used[u])
            dfs2(u);
}

pair<int,int> compute(int idx) {
    if(dp[idx].first != 0) return dp[idx];

    pair<int,int> ret = root_size_weight[idx];

    pair<int,int> best = make_pair(0,0);
    for(auto e: adj_scc[idx]) {
        auto p = compute(e);
        if(p.first > best.first) best = p;
        if(p.first == best.first && p.second < best.second) best = p;
    }

    ret.first += best.first;
    ret.second += best.second;

    return dp[idx] = ret;
}

void solve() {
    int n,m;
    cin >> n >> m;

    a = vector<int>(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    adj = vector<vector<int>>(n+1);
    adj_rev = vector<vector<int>>(n+1);

    set<pair<int,int>> s;
    while(m--) {
        int u,v;
        cin >> u >> v;

        if(u == v || s.find({u,v}) != s.end()) continue;

        adj[u].push_back(v);
        adj_rev[v].push_back(u);

        s.insert({u,v});
    }

    used.assign(n+1, false);

    for (int i = 1; i <= n; i++)  {
        if (!used[i]) {
            dfs1(i);
        }
    }

    used.assign(n, false);
    reverse(order.begin(), order.end());

    roots = vector<int> (n+1, 0);
    root_nodes = vector<int>();
    adj_scc = vector<vector<int>>(n+1);

    root_size_weight = vector<pair<int,int>>(n+1, make_pair(0,0));
    dp = vector<pair<int,int>>(n+1, make_pair(0,0));

    for (auto v : order) {
        if (!used[v]) {
            dfs2 (v);

            int root = component.front();
            for (auto u : component) {
                roots[u] = root;
                root_size_weight[root].first++;
                root_size_weight[root].second += a[u];
            }
            root_nodes.push_back(root);

            component.clear();
        }
    }

    for (int v = 1; v <= n; v++) {
        for (auto u : adj[v]) {
            int root_v = roots[v];
            int root_u = roots[u];

            if (root_u != root_v) {
                adj_scc[root_v].push_back(root_u);
            }
        }
    }

    for(int v = 1; v <= n; v++) {
        compute(v);
    }

    pair<int,int> best = make_pair(0,0);
    for(auto p: dp) {
        if(p.first > best.first) best = p;
        if(p.first == best.first && p.second < best.second) best = p;
    }

    cout << best.first << " " << best.second << "\n";
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct two_sat {
    int n;
    vector<vector<int>> g, gr; // gr is the reversed graph
    vector<int> comp, topological_order, answer; // comp[v]: ID of the SCC containing node v
    vector<bool> vis;

    two_sat() {}

    two_sat(int _n) { init(_n); }

    void init(int _n) {
        n = _n;
        g.assign(2 * n, vector<int>());
        gr.assign(2 * n, vector<int>());
        comp.resize(2 * n);
        vis.resize(2 * n);
        answer.resize(2 * n);
    }

    void add_edge(int u, int v) {
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    // At least one of them is true
    void add_clause_or(int i, bool f, int j, bool g) {
        add_edge(i + (f ? n : 0), j + (g ? 0 : n));
        add_edge(j + (g ? n : 0), i + (f ? 0 : n));
    }

    // Topological sort
    void dfs(int u) {
        vis[u] = true;

        for (const auto &v : g[u])
            if (!vis[v]) dfs(v);

        topological_order.push_back(u);
    }

    // Extracting strongly connected components
    void scc(int u, int id) {
        vis[u] = true;
        comp[u] = id;

        for (const auto &v : gr[u])
            if (!vis[v]) scc(v, id);
    }

    // Returns true if the given proposition is satisfiable and constructs a valid assignment
    bool satisfiable() {
        fill(vis.begin(), vis.end(), false);

        for (int i = 0; i < 2 * n; i++)
            if (!vis[i]) dfs(i);

        fill(vis.begin(), vis.end(), false);
        reverse(topological_order.begin(), topological_order.end());

        int id = 0;
        for (const auto &v : topological_order)
            if (!vis[v]) scc(v, id++);

        // Constructing the answer
        for (int i = 0; i < n; i++) {
            if (comp[i] == comp[i + n]) return false;
            answer[i] = (comp[i] > comp[i + n] ? 1 : 0);
        }

        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    
    vector<vector<int>> g(3, vector<int>(n));
    for(int i = 0; i < n;i++) cin >> g[0][i];
    for(int i = 0; i < n;i++) cin >> g[1][i];
    for(int i = 0; i < n;i++) cin >> g[2][i];

    two_sat sat(n+1);
    for(int i = 0; i < n;i++) {
        sat.add_clause_or(abs(g[0][i]), g[0][i] > 0, abs(g[1][i]), g[1][i] > 0);
        sat.add_clause_or(abs(g[2][i]), g[2][i] > 0, abs(g[1][i]), g[1][i] > 0);
        sat.add_clause_or(abs(g[0][i]), g[0][i] > 0, abs(g[2][i]), g[2][i] > 0);
    }

    cout << (sat.satisfiable() ? "YES" : "NO") << "\n";
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

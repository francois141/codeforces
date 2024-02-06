#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<pair<int,int>>> graph;
set<pair<int,int>> s;

vector<bool> visited;
vector<int> tin, low;
int timer;
int n,m;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (pair<int,int> pai : graph[v]) {
        int to = pai.first;
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                s.insert(make_pair(min(to,v), max(to,v)));
            }
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n+1, false);
    tin.assign(n+1, -1);
    low.assign(n+1, -1);
    for (int i = 1; i <= n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

vector<int> path;
int from, to;

void dfs(int current, int parent, vector<int>&p) {
    if(visited[current]) return;
    visited[current] = true;

    p.push_back(current);

    if(current == to) {
        path = p;
        return;
    }

    for(auto e: graph[current]) {
        if(e.first == parent) continue;
        dfs(e.first, current, p);
    }

    p.pop_back();
}

void solve() {

    cin >> n >> m;

    graph = vector<vector<pair<int,int>>>(n+1);
    s.clear();

    for(int i = 0; i < m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }

    // First get forbidden values
    find_bridges();

    // get best one
    int value = INT_MAX;
    for(int i = 1; i <= n;i++) {
        for(auto j: graph[i]) {
            if(s.find(make_pair(min(i,j.first), max(i,j.first))) == s.end() && j.second < value) {
                from = i;
                to = j.first;
                value = j.second;
            }
        }
    }

    // Run the dfs
    path = vector<int>();
    vector<int> tmp = vector<int>();
    visited = vector<bool>(n+1, false);

    dfs(from, to, tmp);

    cout << value << " " << path.size() << "\n";
    for(auto e: path) cout << e << " ";
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

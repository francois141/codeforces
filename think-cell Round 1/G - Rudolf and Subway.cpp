#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<pair<int, int>>> adj;

int dijkstra(int s, int t) {
    const int INF = INT_MAX;

    int n = adj.size();
    vector<int> d(n,INF);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }

    return d[t] / 2;
}

void solve() {
    int n,m;
    cin >> n >> m;

    adj = vector<vector<pair<int,int>>>(n+1);

    map<pair<int,int>,int> mp;
    for(int i = 0; i < m;i++) {
        int u,v,c;
        cin >> u >> v >> c;

        if(mp.find({u,c}) == mp.end()) {
            int newIdx = adj.size();
            mp[{u,c}] = newIdx;
            adj.push_back(vector<pair<int,int>>(0));
            adj[u].push_back({newIdx, 1});
            adj[newIdx].push_back({ u, 1});
        }

        if(mp.find({v,c}) == mp.end()) {
            int newIdx = adj.size();
            mp[{v,c}] = newIdx;
            adj.push_back(vector<pair<int,int>>(0));
            adj[v].push_back({newIdx, 1});
            adj[newIdx].push_back({ v, 1});
        }

        u = mp[{u,c}];
        v = mp[{v,c}];

        adj[u].push_back({v,0});
        adj[v].push_back({u,0});
    }

    int b,e;
    cin >> b >> e;

    cout << dijkstra(b,e) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

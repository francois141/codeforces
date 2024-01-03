#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
vector<vector<pair<int,int>>> graph;
vector<int> s;

int dijkstra() {

    map<int,vector<int>> d;
    for(int i = 1; i <= n;i++){
        d[s[i]] = vector<int>(n+1, LLONG_MAX);
    }

    d[s[1]][1] = 0;
    set<pair<int, pair<int,int>>> q;
    q.insert(make_pair(0, make_pair(1,s[1])));
    while (!q.empty()) {
        pair<int,int> v = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : graph[v.first]) {
            int to = edge.first;
            int len = edge.second;
            if (d[v.second][v.first] + len * v.second < d[min(v.second, s[to])][to]) {
                d[min(v.second, s[to])][to] = d[v.second][v.first] + len * v.second;
                q.insert(make_pair(d[v.second][to], make_pair(to, min(v.second, s[to]))));
            }
        }
    }

    int ret = LLONG_MAX;

    for(auto e: d) {
        ret = min(ret, e.second[n]);
    }

    return ret;
}

void solve() {
    cin >> n >> m;

    graph = vector<vector<pair<int,int>>>(n+1);
    for(int i = 0; i < m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }

    s = vector<int>(n+1);
    for(int i = 1; i <= n;i++) cin >> s[i];

    cout << dijkstra() << "\n";
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

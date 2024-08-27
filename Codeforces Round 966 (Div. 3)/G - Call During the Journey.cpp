#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge {
    int to;
    int bus;
    int foot;
};

vector<vector<edge>> graph;

int n,m;
int tevent,t1,t2;

const int INF = INT_MAX;
bool dijkstra(int t_start) {
    int s = 1;
    vector<int> d(n+1, INF);

    d[s] = t_start;
    set<pair<int, int>> q;
    q.insert({t_start, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        int currentDistance = q.begin()->first;
        q.erase(q.begin());

        for (auto e : graph[v]) {
            int to = e.to;

            // Case foot
            if (d[v] + e.foot < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + e.foot;
                q.insert({d[to], to});
            }

            // Case bus
            int until = 0;
            if(t1 <= currentDistance && currentDistance <= t2) {
                until = t2 + e.bus;
            } else if(d[v] < t1 && d[v] + e.bus > t1) {
                until = t2 + e.bus;
            } else {
                until = d[v] + e.bus;
            }

            if (until < d[to]) {
                q.erase({d[to], to});
                d[to] = until;
                q.insert({d[to], to});
            }
        }
    }

    return d[n] <= tevent;
}

void solve() {
    cin >> n >> m;

    cin >> tevent >> t1 >> t2;

    graph = vector<vector<edge>>(n+1);
    for(int i = 0; i < m;i++) {
        int u,v, bus, edge;
        cin >> u >> v >> bus >> edge;
        graph[u].push_back({v,bus,edge});
        graph[v].push_back({u,bus,edge});
    }

    if(!dijkstra(0)) {
        cout << -1 << "\n";
        return;
    }

    int start = 0;
    int end = 1e9+1;

    while(start != end) {
        int middle = (start + end + 1) / 2;
        if(dijkstra(middle)) {
            start = middle;
        } else {
            end = middle-1;
        }
    }

    cout << start << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

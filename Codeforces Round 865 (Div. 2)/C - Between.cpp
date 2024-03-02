#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> graph;
vector<int> depth;
vector<vector<int>> values;

void solve() {
    int n,m;
    cin >> n >> m;

    graph = vector<vector<int>>(n+1);
    values = vector<vector<int>>(n+1);
    depth = vector<int>(n+1);

    for(int i = 0; i < m;i++) {
        int from, to;
        cin >> to >> from;
        graph[from].push_back(to);
    }

    // run bfs
    queue<int> q;
    vector<bool> visited(n+1,false);
    vector<int> order;

    q.push(1);
    visited[1] = true;
    depth[1] = 1;
    values[1].push_back(1);

    while(!q.empty()) {
        int next = q.front();
        q.pop();
        for(auto child: graph[next]) {
            if(!visited[child]) {
                visited[child] = true;
                depth[child] = depth[next]+1;
                values[depth[child]].push_back(child);
                order.push_back(child);
                q.push(child);
            }
        }
    }

    for(int i = 1; i <= n;i++) {
        if(!visited[i]) {
            cout << "INFINITE" << "\n";
            return;
        }
    }

    cout << "FINITE" << "\n";

    vector<int> answer;

    for(int i = values.size()-1;i >= 1;i--) {
        for(auto e: values[i]) {
            answer.push_back(e);
            values[i-1].push_back(e);
        }
    }

    cout << answer.size() << "\n";
    for(auto e: answer) cout << e << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

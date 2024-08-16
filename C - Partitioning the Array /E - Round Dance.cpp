#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<set<int>> graph;
vector<bool> visited;

int dfs(int curr, int p) {
    visited[curr] = true;

    int ret = 1;

    for(auto e: graph[curr]) {
        if(e == p) continue;

        // Cycle found
        if(visited[e]) {
            return 0;
        }

        ret = min(ret, dfs(e, curr));
    }

    return ret;
}

void solve() {
    int n;
    cin >> n;

    graph = vector<set<int>>(n+1);
    for(int i = 1; i <= n;i++) {
        int a;
        cin >> a;
        graph[a].insert(i);
        graph[i].insert(a);
    }

    visited = vector<bool>(n+1,false);
    
    pair<int,int> res;
    for(int i = 1; i <= n;i++) {
        if(!visited[i]) {
            if(dfs(i, 0)) {
                res.first++;
            } else {
                res.second++;
            }
        }
    }

    cout << min(res.first, 1ll) + res.second << " " << res.first + res.second << "\n";    
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


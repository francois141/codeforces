#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,c;

vector<vector<int>> graph;
vector<int> a;

pair<int,int> dfs(int curr, int p) {
    pair<int,int> ret = make_pair(0,a[curr]);

    for(auto child: graph[curr]) {
        if(child != p) {
            auto e = dfs(child, curr);
            ret.first += max(e.first, e.second);
            ret.second += max(e.first, e.second - 2*c);
        }

    }

    return ret;
}

void solve() {
    cin >> n >> c;

    a = vector<int> (n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    graph = vector<vector<int>>(n+1);
    for(int i = 0; i < n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v); 
        graph[v].push_back(u);
    }

    auto p = dfs(1,0);

    cout << max(p.first, p.second) << "\n";
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

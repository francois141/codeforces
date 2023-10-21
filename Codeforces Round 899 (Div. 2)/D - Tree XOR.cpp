#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;
vector<pair<int,int>> res;
vector<vector<int>> graph;
vector<int> output;

pair<int,int> dfs1(int curr, int p) {
    pair<int,int> out = {0,1};

    for(auto c: graph[curr]) {
        if (c == p) continue;
        auto tmp = dfs1(c, curr);

        out.first += tmp.first + (a[curr] ^ a[c]) * tmp.second;
        out.second += tmp.second;
    }

    return res[curr] = out;
}

void dfs2(int curr, pair<int,int> s, int p) {
    // Adjust
    s.first += + (a[curr] ^ a[p]) * s.second;

    // Give score
    output[curr] = res[curr].first + s.first;

    for(auto c: graph[curr]) {
        if (c == p) continue;

        auto s2 = res[curr];
        // Remove child
        s2.first -= res[c].first + (a[curr] ^ a[c]) * res[c].second;
        s2.second -= res[c].second;
        // Add "parent" branch
        s2.first += s.first;
        s2.second += s.second;
        // Compute
        dfs2(c, s2,  curr);
    }
}

void solve() {
    int n;
    cin >> n;

    a = vector<int>(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    graph = vector<vector<int>>(n+1);
    for(int i = 0; i < n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    res = vector<pair<int,int>>(n+1);
    output = vector<int>(n+1);

    dfs1(1, 0);

    dfs2(1, {0,0}, 0);

    for(int i = 1; i <= n;i++) {
        cout << output[i] << " ";
    } cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

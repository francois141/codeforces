#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> graph;
vector<int> sizes;

int dfs(int curr) {
    int ans = 1;
    for(auto e: graph[curr]) ans += dfs(e);
    return sizes[curr] = ans;
}

void solve() {
    int n;
    cin >> n;

    graph = vector<vector<int>>(n+1);
    for(int i = 0; i < n-1;i++) {
        int x;
        cin >> x;
        graph[x].push_back(i+2);
    }

    sizes = vector<int>(n+1);

    dfs(1);

    set<pair<int,int>> s;
    for(auto e: graph[1]) {
        s.insert(make_pair(-sizes[e], e));
    }

    int ans = 0;

    while(!s.empty()) {
        if(s.size() == 1) {
            auto p = *s.begin(); s.erase(s.begin());
            for(auto e : graph[p.second]) s.insert(make_pair(-sizes[e], e));
        } else {
            auto p1 = *s.begin(); s.erase(s.begin());
            auto p2 = *s.begin(); s.erase(s.begin());
            ans++;
            for(auto e : graph[p1.second]) s.insert(make_pair(-sizes[e], e));
            for(auto e : graph[p2.second]) s.insert(make_pair(-sizes[e], e));
        }
    }

    cout << ans << "\n";
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

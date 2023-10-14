#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> graph;
vector<bool> a;

int ans;

int dfs(int curr, int p = -1) {
    multiset<int> val;
    val.insert(INT_MIN);

    if(a[curr]) {
        val.insert(0);
    }

    for(auto child: graph[curr]) {
        if(child == p) continue;
        val.insert(dfs(child, curr) + 1);
        if(val.size() > 2) {
            val.erase(val.begin());
        }
    }

    if(val.size() >= 2) {
        ans = max(ans, (*val.rbegin() + *prev(val.rbegin())+1) / 2);
    }

    return (*val.rbegin() < 0 ? INT_MIN : *val.rbegin());
}

void solve() {
    int n,k;
    cin >> n >> k;

    a = vector<bool>(n+1,false);
    for(int i = 0; i < k;i++) {
        int idx; cin >> idx;
        a[idx] = true;
    }

    graph = vector<vector<int>>(n+1,vector<int>());
    for(int i = 0; i < n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ans = 0;

    dfs(1);

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}

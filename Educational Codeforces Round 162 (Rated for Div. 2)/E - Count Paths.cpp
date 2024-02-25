#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> c;
vector<vector<int>> graph;
int answer = 0;

map<int,int>& dfs(int current, int p = -1) {

    vector<map<int,int>*> values;
    for(auto e: graph[current]) {
        if(e == p) continue;
        values.push_back(&dfs(e, current));
    }

    if(values.empty()) {
        auto ret = new map<int,int>;
        ret->insert(make_pair(c[current], 1));
        return *ret;
    }

    sort(values.begin(), values.end(), [](auto e1, auto e2) {
        return e1->size() > e2->size();
    });

    int currentColor = c[current];

    for(int i = 1; i < values.size();i++) {
        for(auto &pair: *values[i]) {
            if(pair.first == currentColor) {
                (*values[0])[pair.first] += pair.second;
            } else {
                answer += pair.second * (*values[0])[pair.first];
                (*values[0])[pair.first] += pair.second;
            }
        }
    }

    answer += (*values[0])[currentColor];
    (*values[0])[currentColor] = 1;

    return *values[0];
}

void solve() {
    int n;
    cin >> n;

    c = vector<int>(n+1);
    for(int i = 1; i <= n;i++) cin >> c[i];

    graph = vector<vector<int>>(n+1);
    for(int i = 0; i < n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    answer = 0;

    dfs(1);

    cout << answer << "\n";
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

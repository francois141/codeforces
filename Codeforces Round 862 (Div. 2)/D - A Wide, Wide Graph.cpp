#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>> graph;

int dist;
pair<int,int> best;


pair<int,int> dfs1(int curr, int p = -1) {
    vector<pair<int,int>> childs;

    childs.push_back({0, curr});
    for(auto e: graph[curr]) {
        if(e == p) continue;
        childs.push_back(dfs1(e, curr));
    }

    sort(childs.rbegin(), childs.rend());
    if(childs.size() >= 2 && childs[0].first + childs[1].first > dist) {
        dist = childs[0].first + childs[1].first;
        best = {childs[0].second, childs[1].second};
    }

    childs[0].first++;
    return childs[0];
}

vector<int> distances;
void dfs2(int curr, int dist, int p = -1) {
    distances[curr] = max(distances[curr], dist);
    for(auto child: graph[curr]) {
        if(child != p) dfs2(child, dist+1, curr);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    graph = vector<vector<int>>(n, vector<int>());

    for(int i = 0; i < n-1;i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dist = INT_MIN;
    distances = vector<int>(n, 0);

    dfs1(0);

    dfs2(best.first, 0);
    dfs2(best.second, 0);

    sort(distances.begin(), distances.end());

    vector<int> z;
    int ans = n+1;

    int k = n;
    while(k > 0) {
        while(!distances.empty() && distances.back() >= k) {
            distances.pop_back();
            ans--;
        }
        z.push_back(min(ans, n));
        k--;
    }

    reverse(z.begin(), z.end());
    for(auto e: z) cout << e << " ";
    cout << endl;
    return 0;
}
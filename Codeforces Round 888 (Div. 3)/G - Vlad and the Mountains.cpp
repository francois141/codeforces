#include <bits/stdc++.h>
#define int long long
using namespace std;

struct edge {
    int u;
    int v;
    int until;
};

struct query {
    string ans;
    int e,a,b;
    int idx;
};

vector<int> heights;
vector<int> parent;

int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    parent[a] = b;
}

void solve() {
    int n,m;
    cin >> n >> m;

    heights = vector<int>(n+1);
    for(int i = 1; i <= n;i++) {
        cin >> heights[i];
    }

    vector<edge> edges;
    for(int i = 0; i < m;i++) {
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v,max(heights[u], heights[v])});
    }

    sort(edges.begin(), edges.end(), [](auto e1, auto e2) {
        return e1.until < e2.until;
    });

    parent = vector<int>(n+1);
    iota(parent.begin(), parent.end(), 0);

    int q; cin >> q;

    vector<query> queries(q);
    for(int i = 0; i < q;i++) {
        cin >> queries[i].a;
        cin >> queries[i].b;
        cin >> queries[i].e;
        queries[i].e += heights[queries[i].a];
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end(), [](auto e1, auto e2) {
        return e1.e < e2.e;
    });

    int idx = 0;
    for(query &quer : queries) {
        while(idx < edges.size() && edges[idx].until <= quer.e) {
            unite(edges[idx].u, edges[idx].v);
            idx++;
        }

        if(find(quer.a) == find(quer.b)) {
            quer.ans = "YES";
        } else {
            quer.ans = "NO";
        }
    }

    sort(queries.begin(), queries.end(), [](auto e1, auto e2) {
        return e1.idx < e2.idx;
    });

    for(auto e : queries) {
        cout << e.ans << "\n";
    }
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

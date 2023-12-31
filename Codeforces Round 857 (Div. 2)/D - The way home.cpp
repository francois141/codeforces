#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> w;

bool comp(pair<int,int> p1, pair<int,int> p2) {
    return p1.first < p2.first || (p1.first == p2.first && p1.second < p2.second);
}

pair<int,int> add(pair<int,int> p1, int s, int w) {
    p1.second += s;
    if(p1.second > 0) {
        int toAdd = ceil(p1.second / ((double)w));
        p1.first += toAdd;
        p1.second -= toAdd * w;
    }
    return p1;
}

void solve() {
    int n,m,p;
    cin >> n >> m >> p;

    w = vector<int>(n+1);
    for(int i = 1; i <= n;i++) cin >> w[i];

    graph = vector<vector<pair<int,int>>>(n+1);
    for(int i = 0; i < m;i++) {
        int a,b,s;
        cin >> a >> b >> s;
        graph[a].push_back({b,s});
    }

    vector<map<int,pair<int,int>>> d(n+1);
    for(int i = 1; i <= n;i++) {
        for(int j = 1; j <= n;j++) {
            d[i][w[j]] = make_pair(LLONG_MAX, LLONG_MAX);
        }
    }

    // First: distance (spectacles, money)
    // Second: next, w_next
    set<pair<pair<int,int>,pair<int,int>>> q;
    q.insert(make_pair(make_pair(0,-p),make_pair(1,w[1])));
    while (!q.empty()) {
        pair<int,int> distance = q.begin()->first;
        pair<int,int> next = q.begin()->second;
        q.erase(q.begin());

        for (auto edge : graph[next.first]) {
            int to = edge.first;
            int costTravel = edge.second;

            int nextGenerator = max(next.second, w[to]);
            pair<int,int> newDistance = add(distance,costTravel, next.second);

            // Comparaison
            if (comp(newDistance,d[to][nextGenerator])) {
                d[to][nextGenerator] = add(distance,costTravel, next.second);
                // Insert the value
                q.insert(make_pair(d[to][nextGenerator] ,make_pair(to,nextGenerator)));
            }
        }
    }

    int ans = LLONG_MAX;
    for(auto e: d[n]) {
        ans = min(ans, e.second.first);
    }
    if(ans == LLONG_MAX) ans = -1;

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

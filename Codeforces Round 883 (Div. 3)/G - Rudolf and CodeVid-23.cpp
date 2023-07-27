#include <bits/stdc++.h>
#define int long long
using namespace std;

struct medicine {
    int dist;
    int more;
    int less;
};

vector<medicine> medicines;

int dijkstra(int s) {
    const int INF = INT_MAX;

    int n = 1025;
    vector<int> d(1025, INF);

    d[s] = 0;
    set<pair<int, int>> q;
    q.insert({0, s});
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (auto med : medicines) {
            int to = (v & (~med.less)) | med.more;
            int len = med.dist;
            if (d[v] + len < d[to]) {
                q.erase({d[to], to});
                d[to] = d[v] + len;
                q.insert({d[to], to});
            }
        }
    }

    return d[0] == INF ? -1 : d[0];
}

int convert(string s) {
    int val = 0;
    while(!s.empty()) {
        if(s.back() == '1') {
            val += pow(2,s.size()-1);
        }
        s.pop_back();
    }
    return val;
}

void solve() {
    int n,m;
    cin >> n >> m;

    string start;
    cin >> start;
    int from = convert(start);

    medicines = vector<medicine>(m);
    for(int i = 0; i < m;i++) {
        cin >> medicines[i].dist;
        string tmp;
        cin >> tmp;
        medicines[i].less = convert(tmp);
        cin >> tmp;
        medicines[i].more = convert(tmp);
    }

    cout << dijkstra(from) << "\n";
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> grid;
vector<vector<int>> dist;
vector<vector<bool>> visited;

void solve() {
    int n,m;
    cin >> n >> m;

    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    grid = vector<vector<int>>(n, vector<int>(m, false));
    dist = vector<vector<int>>(n, vector<int>(m, INT_MAX));

    for(int i = 0; i < n;i++) {
        for(int j = 0; j < m;j++) {
            cin >> grid[i][j];
        }
    }

    int answer = INT_MAX;

    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 0;

    // Run BFS
    while(!q.empty()) {
        auto c = q.front(); q.pop();

        if(c.second == m || visited[c.first][c.second]) continue;
        visited[c.first][c.second] = true;

        if(c.second == m-1) {
            answer = min(answer, dist[c.first][c.second] + (c.first + 1) % n);
        }

        if(!grid[(dist[c.first][c.second] + c.first + 1) % n][c.second+1]) {
            q.push({c.first, c.second+1});
            dist[c.first][c.second+1] = min(dist[c.first][c.second+1],1 + dist[c.first][c.second]);
        }

        bool c1 = grid[(dist[c.first][c.second] + c.first + 1) % n][c.second];
        bool c2 = grid[(dist[c.first][c.second] + c.first + 2) % n][c.second];
        if(!c1 && !c2) {
            q.push({(c.first+1) % n, c.second});
            dist[(c.first+1) % n][c.second] = min(dist[(c.first+1) % n][c.second],1 + dist[c.first][c.second]);
        }
    }

    cout << ((answer == INT_MAX) ? -1 : answer) << "\n";
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

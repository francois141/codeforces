#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<string> grid;

struct cmp {
    int x1;
    int x2;
    int y1;
    int y2;
    int size;
};

cmp dfs(int x, int y) {
    if(x < 0 || x == grid.size()) return {INT_MAX, 0, INT_MAX, 0, 0};
    if(y < 0 || y == grid[0].size()) return {INT_MAX, 0, INT_MAX, 0, 0};
    if(grid[x][y] != '#') return {INT_MAX, 0, INT_MAX, 0, 0};
    grid[x][y] = '_';

    cmp output = {
            x-1,x+1,y-1,y+1,1
    };

    vector<pair<int,int>> v = {make_pair(x-1,y), make_pair(x+1,y),make_pair(x,y+1),make_pair(x,y-1)};
    for(auto e: v) {
        auto c = dfs(e.first, e.second);
        output.size += c.size;
        output.x1 = min(output.x1, c.x1);
        output.y1 = min(output.y1, c.y1);
        output.x2 = max(output.x2, c.x2);
        output.y2 = max(output.y2, c.y2);
    }

    return output;
}

void solve() {
    cin >> n >> m;

    grid = vector<string>(n);
    for(int i = 0; i < n;i++) cin >> grid[i];

    vector<int> valuesX(n);
    vector<int> valuesY(m);

    // Horizontal
    for(int i = 0; i < n;i++) {
        int cnt = 0;
        for(int j = 0; j < m;j++) cnt += (grid[i][j] == '.') ? 1 : 0;
        valuesX[i] = cnt;
    }

    // Vertical
    for(int j = 0; j < m;j++) {
        int cnt = 0;
        for(int i = 0; i < n;i++) cnt += (grid[i][j] == '.') ? 1 : 0;
        valuesY[j] = cnt;
    }

    vector<vector<int>> prefix(n+2, vector<int>(m+2));
    for(int i = 0; i < n;i++) {
        for(int j = 0; j < m;j++) {
            if(grid[i][j] == '#') {
                auto c = dfs(i,j);
                c.x1 = max(c.x1, 0);
                c.y1 = max(c.y1, 0);

                // Horizontal
                prefix[c.x1][0] += c.size;
                prefix[c.x2+1][0] -= c.size;

                // Vertical
                prefix[0][c.y1] += c.size;
                prefix[0][c.y2+1] -= c.size;

                // Middle
                prefix[c.x1][c.y1] -= c.size;
                prefix[c.x1][c.y2+1] += c.size;
                prefix[c.x2+1][c.y1] += c.size;
                prefix[c.x2+1][c.y2+1] -= c.size;
            }
        }
    }

    int ans = 0;

    for(int i = 0; i < n;i++) {
        for(int j = 0; j < m;j++) {
            if(i > 0) prefix[i][j] += prefix[i-1][j];
            if(j > 0) prefix[i][j] += prefix[i][j-1];
            if(i > 0 && j > 0) prefix[i][j] -= prefix[i-1][j-1];

            int malus = (grid[i][j] == '.') ? -1 : 0;
            ans = max(ans, prefix[i][j] + valuesX[i] + valuesY[j] + malus);
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
}

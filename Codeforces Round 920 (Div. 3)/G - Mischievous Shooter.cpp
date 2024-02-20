#include <bits/stdc++.h>
#define int long long
using namespace std;

int compute(vector<string> &grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> prefixVertical(n, vector<int>(m,0));
    for(int j = 0; j < m;j++) {
        prefixVertical[0][j] = (grid[0][j] == '#') ? 1 : 0;
        for(int i = 1; i < n;i++) {
            prefixVertical[i][j] = prefixVertical[i-1][j] + ((grid[i][j] == '#') ? 1 : 0);
        }
    }

    vector<vector<int>> prefixDiagonal(n, vector<int>(m, 0));
    for(int i = 0; i < m + n - 1;i++) {
        for(int j = min(i,n-1); j >= 0 && (i-j) < m;j--) {
            int x = j;
            int y = i - j;

            // Filter out
            if(x >= n || y >= m) continue;

            // Compute
            if(x < n-1 && y > 0) prefixDiagonal[x][y] = prefixDiagonal[x+1][y-1];
            prefixDiagonal[x][y] += (grid[x][y] == '#') ? 1 : 0;
        }
    }

    int answer = 0;

    // First brute force current value
    int firstValue = 0;
    for(int i = 0; i <= min(n,k);i++) {
        for(int j = 0; j <= min(m, k);j++) {
            if(i + j <= k && i < n && j < m && grid[i][j] == '#') firstValue++;
        }
    }

    for(int i = 0; i < n;i++) {
        int current = firstValue;

        answer = max(answer, current);

        for(int j = 0; j < m-1;j++) {
            // Update vertical
            current -= prefixVertical[min(i+k,n-1)][j];
            if(i > 0) current += prefixVertical[i-1][j];
            // Update diagonal
            int difference = (j + k + 1) - (m-1);
            if(difference <= 0) {
                current += prefixDiagonal[i][j+k+1];
            } else if(i + difference < n) {
                current += prefixDiagonal[i + difference][j+k+1 - difference];
            }
            if(i+k+1 < n) current -= prefixDiagonal[i+k+1][j];
            // Get max for answer
            answer = max(answer, current);
        }

        // Between each shoot --> update again with diagonal
        for(int j = 0; j <= min(m,k);j++) {
            firstValue -= (grid[i][j] == '#') ? 1 : 0;
            int x = i + k + 1 - j;
            int y = j;
            if(x >= n) continue;
            firstValue += (grid[x][y] == '#') ? 1 : 0;
        }
    }

    return answer;
}

void solve() {
    int n,m,k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for(int i = 0; i < n;i++) cin >> grid[i];

    int ans = compute(grid, k);

    for(auto &e: grid) reverse(e.begin(), e.end());
    ans = max(ans, compute(grid, k));

    reverse(grid.begin(), grid.end());
    ans = max(ans,compute(grid, k));

    for(auto &e: grid) reverse(e.begin(), e.end());
    ans = max(ans,compute(grid, k));

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

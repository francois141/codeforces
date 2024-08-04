#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> comp;
vector<vector<bool>> visited;
vector<vector<int>> numbers;
vector<string> grid;

int n,m;

void dfs(int i, int j, int val) {
    if(i < 0 || i >= n) return;
    if(j < 0 || j >= m) return;
    if(visited[i][j]) return;
    if(grid[i][j] == '.') return;

    visited[i][j] = true;
    numbers[i][j] = val;
    comp[val]++;

    dfs(i+1, j, val);
    dfs(i-1, j, val);
    dfs(i, j+1, val);
    dfs(i, j-1, val);
} 

int test(int i, int j, set<int> &s) {
    if(i < 0 || i >= n) return 0;
    if(j < 0 || j >= m) return 0;
    if(grid[i][j] == '.') return 0;

    int ret = 0;
    int val = numbers[i][j];
    
    if(s.find(val) == s.end()) ret = comp[val];
    s.insert(val);
    return ret;
}

void solve() {

    cin >> n >> m;

    grid = vector<string>(n);
    for(int i = 0; i < n;i++) cin >> grid[i];

    comp = vector<int>(0);
    visited = vector<vector<bool>>(n, vector<bool>(m,false));
    numbers = vector<vector<int>>(n, vector<int>(m));

    int val = 0;

    for(int i = 0; i < n;i++) {
        for(int j = 0; j < m;j++) {
            if(!visited[i][j]) {
                comp.push_back(0);
                dfs(i, j, val);
                val++;
            }
        }
    }

    int answer = *max_element(comp.begin(), comp.end());

    for(int i = 0; i < n;i++) {
        int curr = 0;
        set<int> s;
        for(int j = 0; j < m;j++) {
            if(grid[i][j] == '.') curr++;

            curr += test(i-1,j, s);
            curr += test(i,  j, s);
            curr += test(i+1,j, s);
        }

        answer = max(answer, curr);
    }

    for(int j = 0; j < m;j++) {
        int curr = 0;
        set<int> s;
        for(int i = 0; i < n;i++) {
            if(grid[i][j] == '.') curr++;

            curr += test(i,j-1, s);
            curr += test(i,j , s);
            curr += test(i,j+1, s);
        }

        answer = max(answer, curr);
    }

    cout << answer << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

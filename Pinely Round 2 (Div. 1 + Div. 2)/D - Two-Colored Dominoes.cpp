#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m;
    cin >> n >> m;

    vector<string> grid(n);
    for(int i = 0; i < n;i++) cin >> grid[i];

    vector<pair<int,int>> c1;
    vector<pair<int,int>> c2;

    map<int,int> mp1;
    map<int,int> mp2;

    for(int i = 0; i < n;i++) {
        for(int j = 0; j < m;j++) {
            if(grid[i][j] == 'L') {
                c1.push_back({i, j});
                mp1[j]++;
            }
            if(grid[i][j] == 'U') {
                c2.push_back({i,j});
                mp2[i]++;
            }
        }
    }

    for(auto p: mp1) {
        if(p.second % 2 == 1) {
            cout << -1 << "\n";
            return;
        }
    }

    for(auto p: mp2) {
        if(p.second % 2 == 1) {
            cout << -1 << "\n";
            return;
        }
    }

    sort(c1.begin(), c1.end(), [](auto e1, auto e2){
        return e1.second < e2.second;
    });

    sort(c2.begin(), c2.end(), [](auto e1, auto e2){
        return e1.first < e2.first;
    });

    vector<vector<char>> ans(n, vector<char>(m,'.'));

    for(int i = 0; i < c1.size();i+=2) {
        {
            auto dim = c1[i];
            ans[dim.first][dim.second] = 'W';
            ans[dim.first][dim.second+1] = 'B';
        }
        {
            auto dim = c1[i+1];
            ans[dim.first][dim.second] = 'B';
            ans[dim.first][dim.second+1] = 'W';
        }
    }

    for(int i = 0; i < c2.size();i+=2) {
        {
            auto dim = c2[i];
            ans[dim.first][dim.second] = 'W';
            ans[dim.first+1][dim.second] = 'B';
        }
        {
            auto dim = c2[i+1];
            ans[dim.first][dim.second] = 'B';
            ans[dim.first+1][dim.second] = 'W';
        }
    }

    for(auto tmp: ans) {
        for(auto tmp2: tmp) cout << tmp2;
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

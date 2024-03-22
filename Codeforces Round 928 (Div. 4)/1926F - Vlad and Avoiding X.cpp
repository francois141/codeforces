#include <bits/stdc++.h>
using namespace std;

const vector<pair<int,int>> idx1 = {
        make_pair(1,1),
        make_pair(1,3),
        make_pair(1,5),
        make_pair(3,1),
        make_pair(3,3),
        make_pair(3,5),
        make_pair(5,1),
        make_pair(5,3),
        make_pair(5,5),
        make_pair(2,2),
        make_pair(2,4),
        make_pair(4,2),
        make_pair(4,4),
};

const vector<pair<int,int>> idx2 = {
        make_pair(2,1),
        make_pair(2,3),
        make_pair(2,5),
        make_pair(4,1),
        make_pair(4,3),
        make_pair(4,5),
        make_pair(1,2),
        make_pair(1,4),
        make_pair(3,2),
        make_pair(3,4),
        make_pair(5,2),
        make_pair(5,4),
};

void solve() {
    vector<vector<bool>> grid(7, vector<bool>(7, false));

    for(int i = 0; i < 7;i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < 7;j++) {
            grid[i][j] = (tmp[j] == 'B');
        }
    }

    int ans1 = INT_MAX;
    int ans2 = INT_MAX;

    // First part
    for(int i = 0; i < (1 << 13);i++) {
        auto grid2 = grid;
        for(int j = 0; j < idx1.size();j++) {
            if((i >> j) & 0x1) grid2[idx1[j].first][idx1[j].second] = false;
        }
        bool ok = true;
        for(const auto p: idx1) {
            bool c1 = grid2[p.first][p.second];
            bool c2 = grid2[p.first+1][p.second+1];
            bool c3 = grid2[p.first+1][p.second-1];
            bool c4 = grid2[p.first-1][p.second+1];
            bool c5 = grid2[p.first-1][p.second-1];
            if(c1 && c2 && c3 && c4 && c5) ok = false;
        }
        if(ok) {
            ans1 = min(ans1, __builtin_popcount(i));
        }
    }

    // Second part
    for(int i = 0; i < (1 << 12);i++) {
        auto grid2 = grid;
        for(int j = 0; j < idx2.size();j++) {
            if((i >> j) & 0x1) grid2[idx2[j].first][idx2[j].second] = false;
        }
        bool ok = true;
        for(const auto p: idx2) {
            bool c1 = grid2[p.first][p.second];
            bool c2 = grid2[p.first+1][p.second+1];
            bool c3 = grid2[p.first+1][p.second-1];
            bool c4 = grid2[p.first-1][p.second+1];
            bool c5 = grid2[p.first-1][p.second-1];
            if(c1 && c2 && c3 && c4 && c5) ok = false;
        }
        if(ok) {
            ans2 = min(ans2, __builtin_popcount(i));
        }
    }

    cout << ans1 + ans2 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

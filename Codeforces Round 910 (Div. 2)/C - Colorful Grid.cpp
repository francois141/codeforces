#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,m,k;
    cin >> n >> m >> k;

    if((k - n - m) & 0x1) {
        cout << "NO" << "\n";
        return;
    }

    if(k - n - m + 2 < 0) {
        cout << "NO" << "\n";
        return;
    }

    vector<vector<char>> grid1(n, vector<char>(m-1,'B'));
    vector<vector<char>> grid2(n-1, vector<char>(m,'B'));

    for(int i = 1; i < m-1;i+=2) grid1[0][i] = 'R';
    grid2[0][0] = grid2[0][1] = 'R';

    for(int i = m & 0x1; i < n-1;i+=2) grid2[i].back() = 'R';

    if(grid2.back().back() == 'B') {
        grid2.back()[m-2] = 'R';
    }

    grid1.back().back() = grid1[n-2].back() = grid2.back().back();

    cout << "YES" << "\n";

    for(auto e: grid1) {
        for(auto e2: e) {
            cout << e2 << " ";
        }
        cout << "\n";
    }

    for(auto e: grid2) {
        for(auto e2: e) {
            cout << e2 << " ";
        }
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

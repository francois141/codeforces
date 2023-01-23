#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int counter1  = 1;
    int counter2  = n*n;

    vector<vector<int>> matrix(n,vector<int>(n));
    int r = 0;

    while(counter1 <= counter2) {
        for(int x = 0; x <= r; x++) {
            int y = r-x;

            if(x >= n || y < 0 || y >= n) continue;
        
            if(r % 2 == 0) {
                matrix[x][y] = counter1++;
            } else {
                matrix[x][y] = counter2--;
            }
        }
        r++;
    }

    for(auto m1: matrix) {
        for(auto m2: m1) {
            cout << m2 << " ";
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

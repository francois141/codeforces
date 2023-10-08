#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    vector<int> deg(n+1,0);
    vector<bool> visited(n+1, false);

    vector<int> b(n+1);
    for(int i = 1; i <= n;i++) {
        cin >> b[i];
        deg[b[i]]++;
    }

    if(k == 1) {
        for(int i = 1; i <= n;i++) {
            if(b[i] != i) {
                cout << "NO" << "\n";
                return;
            }
        }

        cout << "YES" << "\n";
        return;
    }

    for(int i = 1; i <= n;i++) {
        int idx = i;
        while(!visited[idx] && deg[idx] == 0) {
            int next = b[idx];
            visited[idx] = true;
            deg[next]--;
            idx = next;
        }
    }

    visited = vector<bool>(n+1,false);

    for(int i = 1; i <= n;i++) {
        if(deg[i] == 0 || visited[i]) continue;

        int size = 1;
        int idx = i;

        visited[idx] = true;
        while(!visited[b[idx]]) {
            idx = b[idx];
            visited[idx] = true;
            size++;
        }

        if(size != k) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
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

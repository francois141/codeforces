#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,q;

void solve() {
    cin >> n >> q;

    vector<int> d(q);
    for(int i = 0; i < q;i++) cin >> d[i];

    for(int i = 0; i < n-1;i++) cout << i+1 << " " <<i+2 << "\n";
    
    int curr = n - 1;
    for(auto e: d) {
        cout << n << " " << curr << " " << e << "\n";
        curr = e;
    }
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


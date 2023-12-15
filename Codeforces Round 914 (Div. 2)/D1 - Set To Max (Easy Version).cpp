#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    vector<int> b(n);
    for(int i = 0; i < n;i++) cin >> b[i];

    for(int i = 0; i < n;i++) {
        bool f = false;

        for(int j = i; j >= 0;j--) {
            if(b[j] < b[i] || a[j] > b[i]) break;
            if(a[j] == b[i]) f = true;
        }

        for(int j = i; j < n;j++) {
            if(b[j] < b[i] || a[j] > b[i]) break;
            if(a[j] == b[i]) f = true;
        }

        if(!f) {
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
}

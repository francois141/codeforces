#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    for(int i = 0; i < n;i++) a[i]++;

    if(a[0] == 1) a[0]++;

    for(int i = 1;i < n;i++) {
        while((a[i] % a[i-1]) == 0) {
            a[i]++;
        } 
    }

    for(auto e: a) cout << e << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

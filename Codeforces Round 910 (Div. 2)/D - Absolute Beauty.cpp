#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n;i++) cin >> b[i];

    for(int i = 0; i < n;i++) {
        if(a[i] > b[i]){
            swap(a[i], b[i]);
        }
    }

    int ans = (*max_element(a.begin(), a.end())) - (*min_element(b.begin(), b.end()));
    ans *= 2;
    ans = max(ans, 0ll);

    for(int i = 0; i < n;i++) ans += b[i] - a[i];

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

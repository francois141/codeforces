#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a,b;
    cin >> a >> b;

    int n,m;
    cin >> n >> m;

    int r = n / (m+1);

    if(m*a < b*(m+1)) {
        int ans = 0;
        ans += m*a*(n/(m+1));
        n = n % (m+1);
        ans += min(a,b)*n;  
        cout << ans << "\n";      
    } else {
        cout << b*n << "\n";
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
#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve() {
    int n,x;
    cin >> n >> x;

    if(n < x) {
        cout << -1 << "\n";
        return;
    }
    int sn = n;

    while((n & sn) != x) {
        n += (n&-n);
        if((n&sn) == 0 && x!=0) break;
    }

    if((n & sn) == x) {
        cout << n << "\n";
    } else {
        cout << -1 << "\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    cout << fixed << setprecision(0);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
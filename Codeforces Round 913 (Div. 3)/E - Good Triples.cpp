#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> fact;

void solve() {
    int n;
    cin >> n;

    int ans = 1;

    while(n > 0) {
        int rem = n % 10;
        ans *= fact[rem + 2] / 2 / fact[rem]; 

        n /= 10;
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    fact = vector<int>(13,1);
    for(int i = 2; i < 13;i++) fact[i] = i * fact[i-1]; 

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}


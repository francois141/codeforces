#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; // or 1e9 + 7;

inline int mult(int a,int b) {return ((a%K)*(b%K)) % K;}
inline int add(int a,int b) {return ((a%K)+(b%K)) % K;}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    for(int i = 1; i <= n;i++) {
        if(a[i] > i || a[i] < a[i-1] || a[i] - a[i-1] >= 3) {
            cout << 0 << "\n";
            return;
        }
    }

    if(a.back() != n) {
        cout << 0 << "\n";
        return;
    }

    vector<int> dp(n+1,1);

    for(int i = 1; i <= n;i++) {
        int left = i-1 - a[i-1];
        if(a[i] == a[i-1]) {
            dp[i] = dp[i-1];
        } else if(a[i] == a[i-1] + 1) {
            dp[i] = mult(dp[i-1],add(left+1,left));
        } else {
            dp[i] = mult(dp[i-1] , mult(left,left));
        }
    }

    cout << dp.back() << "\n";
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int curr = 0;
    for(auto e: a) curr = gcd(curr, e);

    int minVal = *min_element(a.begin(), a.end());
    int ans = curr * (n-1) + minVal;

    while(minVal != curr) {
        int tmp = minVal;
        for(auto e: a) {
            tmp = min(tmp, gcd(minVal, e));
        }
        minVal = tmp;
        ans += tmp - curr;

    }

    cout << ans << "\n";
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

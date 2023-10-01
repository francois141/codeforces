#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

    return (ceil(log2(n)) == floor(log2(n)));
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void solve() {
    int n,m;
    cin >> n >> m;

    n %= m;
    if(n == 0) {
        cout << 0 << "\n";
        return;
    }

    if(!isPowerOfTwo(m / gcd(n,m))) {
        cout << -1 << "\n";
        return;
    }

    int ans = 0;
    while(n > 0) {
        ans += n;
        n *= 2;
        n %= m;
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

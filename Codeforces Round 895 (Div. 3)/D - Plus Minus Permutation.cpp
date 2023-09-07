#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int x, int y) {
    return x*y/gcd(x,y);
}

void solve() {
    int n,x,y;
    cin >> n >> x >> y;

    int com = n / lcm(x,y);

    int v1 = n / x - com;
    int v2 = n / y - com;
    
    int p1 = n * (n+1) / 2 - (n - v1) * (n - v1 + 1) / 2;
    int p2 = v2 * (v2 + 1) / 2;
    
    cout <<  p1-p2  << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

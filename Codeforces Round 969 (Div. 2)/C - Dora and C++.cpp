#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int n,a,b;
    cin >> n >> a >> b;

    vector<int> c(n);
    for(int i = 0; i < n;i++) cin >> c[i];

    if(n == 1) {
        cout << 0 << "\n";
        return;
    }

    int v = gcd(a,b);

    vector<int> s;
    for(auto e: c) {
        s.push_back(e % v);
    }

    sort(s.begin(), s.end());
    s.push_back(s[0] + v);

    int ans = INT_MAX;

    for(int i = 0; i < s.size()-1;i++) {
        ans = min(ans, v - (s[i+1] - s[i]));
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
}Codeforces Round 969 (Div. 2)

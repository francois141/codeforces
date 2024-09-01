#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve()  {
    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int val = a[0];
    for(int i = 1; i < n;i++) {
        val = gcd(val, a[i]);
    }

    int curr = 0;
    if(n == 1) curr = a[0];

    int mex = k-1;

    for(auto e: a) {
        if(curr <= mex) {
            curr += val;
            mex++;
        }
    }

    cout << mex << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}Codeforces Round 970 (Div. 3)

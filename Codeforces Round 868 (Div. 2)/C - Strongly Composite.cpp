#include <bits/stdc++.h>
#define int long long
using namespace std;


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

map<int,int> pr;

void getPrimes(int x) {
    vector<int> ans(0);
    for(int i = 2; i*i <= x;i++) {
        while(x % i == 0) {
            pr[i]++;
            x /= i;
        }
    }
    if(x > 1) {
        pr[x]++;
    }
}

void solve() {
    int n;
    cin >> n;

    pr = map<int,int>();

    int nb = 0;
    for(int i = 0; i < n;i++) {
        int tmp;
        cin >> tmp;
        getPrimes(tmp);
    }

    int ans = 0;
    int b = 0;
    for(auto e: pr) {
        ans += e.second / 2;
        b += e.second  % 2;
    }

    cout << ans + b/3 << "\n";
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
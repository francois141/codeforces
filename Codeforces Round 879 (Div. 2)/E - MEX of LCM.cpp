#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    if(a == LLONG_MAX || b == LLONG_MAX) return LLONG_MAX;
    int g = gcd(a,b);
    a /= g;

    if(LLONG_MAX / a < b) return LLONG_MAX;
    else return a * b;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    set<int> s;
    set<int> s2;
    for(auto e: a) {
        set<int> tmp;
        for(auto e2: s2) tmp.insert(lcm(e2, e));
        tmp.insert(e);
        s2 = tmp;

        for(auto e2: s2) s.insert(e2);
    }

    int curr = 1;
    while(s.find(curr) != s.end()) curr++;
    cout << curr << "\n";
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

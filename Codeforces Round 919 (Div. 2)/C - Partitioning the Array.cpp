#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int test(int value) {
    if(value == a.size()) return 1;

    vector<vector<int>> s(value);
    for(int i = 0; i < value;i++) {
        for(int j = i + value; j < a.size(); j += value) 
        if(abs(a[j] - a[j - value]) > 0)
            s[i].push_back(abs(a[j] - a[j - value]));
    }

    vector<int> tmp;
    for(auto e: s) {
        sort(e.begin(), e.end());
        e.erase(std::unique(e.begin(), e.end()),e.end());
        if(e.size() == 0) continue;
        int curr = e[0];
        for(auto e2: e) curr = gcd(curr, e2);
        if(curr == 1) return 0;
        tmp.push_back(curr);
    }

    if(tmp.empty()) return 1;
    int f = tmp[0];
    for(auto e: tmp) f = gcd(f, e);

    if(f == 1) return 0;

    return 1;
}

void solve() {
    int n;
    cin >> n;

    a = vector<int>(n);
    for(int i = 0;i < n; i++) cin >> a[i];

    int ans = 0;

    for(int i = 1; i <= sqrt(n) + 1;i++) {
        if(n % i == 0) {
            int d2 = n / i;
            if(i > d2) continue;
            ans += test(i);

            if(d2 != i) ans += test(d2);
        }
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


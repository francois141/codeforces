#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    k = k*n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    set<int> s(a.begin(), a.end());
    int missing = 0;
    while(s.find(missing) != s.end()) missing++;

    // Put in permutation
    int idx = 0;
    for(; idx < n && missing < n;idx++) {
        swap(a[idx], missing);
        k--;
    }

    // Shift
    int shift = k / (n+1);
    k -= (n+1)*shift;
    vector<int> a2(n);
    for(int i = 0; i < n;i++) a2[(i+shift) %n] = a[i];
    a = a2;

    // End simulation
    idx += shift;
    while(k--) {
        swap(a[idx % n], missing);
        idx++;
    }

    for(auto e: a) cout << e << " ";
    cout << "\n";
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    sort(a.begin(),a.end(), greater<int>());

    if(a[0] == a.back()) {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";
    cout << a.back() << " ";
    for(int i = 0; i < a.size()-1;i++) cout << a[i] << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

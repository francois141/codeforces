#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 1; i < n;i++) cin >> a[i];

    set<int> values;

    int found = -1;
    int cnt = 0;

    for(int i = 1; i < n;i++) {
        int diff = a[i] - a[i-1];
        if(values.find(diff) != values.end() || diff > n) {
            found = diff;
            cnt++;
        } else {
            values.insert(diff);
        }
    }

    if(cnt > 1) {
        cout << "NO" << endl;
        return;
    }

    int sum = 0;
    for(int i = 1; i <= n;i++) {
        if(values.find(i) == values.end()) {
            sum += i;
        }
    }
    
    if(sum == found || found == -1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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

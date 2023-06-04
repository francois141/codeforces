#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    priority_queue<int> pq;

    int ans = 0;
    for(int i = 0; i < n;i++) {
        int c = a[i];
        if(c == 0) {
            int val;
            if(pq.empty()) val = 0;
            else {
                val = pq.top();
                pq.pop();
            }
            ans += val;
        }
        else {
            pq.push(a[i]);
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
}

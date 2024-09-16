#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k,q;
    cin >> n >> k >> q;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];
    for(int i = 1; i <= n;i++) a[i] -= i;

    vector<int> values(n+1);

    multiset<int> s;
    map<int,int> freq;

    for(int i = 1; i <= n;i++) s.insert(0);

    for(int i = 1; i <= n;i++) {
        s.erase(s.find(freq[a[i]]));
        s.insert(++freq[a[i]]);

        if(i >= k) {
            values[i-k+1] = *s.rbegin();

            s.erase(s.find(freq[a[i-k+1]]));
            s.insert(--freq[a[i-k+1]]);
        }
    }

    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << k - values[l] << "\n";
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

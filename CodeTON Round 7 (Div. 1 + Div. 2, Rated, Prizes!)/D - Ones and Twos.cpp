#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,q;
    cin >> n >> q;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    set<int> s;
    for(int i = 1; i <= n;i++) {
        if(a[i] == 1)
            s.insert(i);
    }

    int sum = accumulate(a.begin(), a.end(), 0ll);

    while(q--) {
        int op; cin >> op;

        if(op == 1) {
            int val;
            cin >> val;


            if(sum < val) {
                cout << "NO" << "\n";
                continue;
            }

            if(s.empty()) {
                cout << ((val & 0x1) ? "NO" : "YES") << "\n";
                continue;
            }

            bool c1 = val % 2 == 1 && s.size() % 2 == 0;
            bool c2 = val % 2 == 0 && s.size() % 2 == 1;


            if(c1 || c2) {
                int minVal = 2*min(*s.begin() - 1, n - *s.rbegin());
                if(sum - minVal - 1< val) {
                    cout << "NO" << "\n";
                    continue;
                }
            }

            cout << "YES" << "\n";
        } else {
            int i,v;
            cin >> i >> v;

            if(s.find(i) != s.end())  {
                sum--;
                s.erase(s.find(i));
            } else {
                sum -= 2;
            }

            sum += v;
            if(v == 1) s.insert(i);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

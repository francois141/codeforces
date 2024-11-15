#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000000;
vector<int> lp(N+1);
vector<int> pr;

void linearSieve()  {
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    set<int> s;
    for(auto e: a) {
        if(lp[e] == e) {
            s.insert(e);
        }
    }

    if(s.size() >= 2) {
        cout << -1 << "\n";
        return;
    }

    if(s.empty()) {
        cout << 2 << "\n";
        return;
    }

    int val = *s.begin();

    for(auto e: a) {
        if(e == val) continue;

        // Pair
        if(e % 2 == 0) {
            if(e < 2*val) {
                cout << -1 << "\n";
                return;
            }
        } else {
            // Not pair
            bool ok = false;
            for(int i = 3; i <= ceil(sqrt(e)); i+=2) {
                if(e % i == 0)  {
                    if(e - i >= 2*val) ok = true;
                }
            }

            if(!ok) {
                cout << -1 << "\n";
                return;
            }
        }
    }

    cout << val << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    linearSieve();

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

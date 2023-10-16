#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
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

    map<int,int> mp;

    for(int i = 0; i < n;i++) {
        int x;
        cin >> x;
        while(x > 1) {
            mp[lp[x]]++;
            x /= lp[x];
        }
    }

    for(auto e: mp) {
        if(e.second % n != 0) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    linearSieve();

    int t;
    cin >> t;

    while(t--)
        solve();
}

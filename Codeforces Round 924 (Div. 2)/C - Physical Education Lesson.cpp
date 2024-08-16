#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,x;
    cin >> n >> x;

    unordered_set<int> ans;



    // Iter 1
    int curr = n - x;
    for(int i = 1; i <= ceil(sqrt(curr));i++) {
        if(curr % i == 0) {
            int d1 = curr / i;
            int d2 = i;
            
            if(d1 % 2 == 0) {
                int v = (d1 + 2) / 2;
                if(v > 1) ans.insert(v);
            }

            if(d2 % 2 == 0) {
                int v = (d2 + 2) / 2;
                if(v > 1) ans.insert(v);
            }
        }
    }

    // Iter 2
    curr = 2*n - 2 + x - n;
    for(int i = 1; i <= ceil(sqrt(curr));i++) {
        if(curr % i == 0) {
            int d1 = curr / i;
            int d2 = i;

            if(d1 % 2 == 0) {
                int v = (d1 + 2) / 2;
                if(v > 1) ans.insert(v);
            }

            if(d2 % 2 == 0) {
                int v = (d2 + 2) / 2;
                if(v > 1) ans.insert(v);
            }
        }
    }

    int cnt = 0;
    for(auto e: ans) if(e >= x) cnt++;

    cout << cnt << "\n";
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


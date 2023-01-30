#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,s,r;
    cin >> n >> s >> r;

    int diff1 = s - r;

    n--;
    int base = r / n;
    int rem = r % n;

    vector<int> ans(0);
    ans.push_back(diff1);

    for(int i = 0; i < n;i++) {
        if(rem > 0) {
            rem--;
            ans.push_back(base+1);
        } else {
            ans.push_back(base);
        }
    }

    for(auto e: ans) {
        cout << e << " ";
    } cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}
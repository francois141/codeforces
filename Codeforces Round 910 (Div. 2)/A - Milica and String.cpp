#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    string s;
    cin >> s;

    int cntK = count(s.begin(), s.end(), 'B');

    if(cntK == k) {
        cout << 0 << "\n";
        return;
    } else if(cntK < k) {
        int idx = 0;
        while(cntK < k) {
            if(s[idx] == 'A') cntK++;
            idx++;
        }
        cout << 1 << "\n";
        cout << idx << " B" << "\n";
    } else {
        int idx = 0;
        while(cntK > k) {
            if(s[idx] == 'B') cntK--;
            idx++;
        }
        cout << 1 << "\n";
        cout << idx << " A" << "\n";
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

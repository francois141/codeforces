#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    
    string pi = "3141592653589793238462643383279502884197169399";

    int idx = 0;
    while(idx < s.size()) {
        if(s[idx] == pi[idx]) {
            idx++;
        } else { 
            break;
        }
    }

    cout << idx << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}
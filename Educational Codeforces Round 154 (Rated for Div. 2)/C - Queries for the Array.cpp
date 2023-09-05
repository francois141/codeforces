#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;

    int currSize = 0;
    int pos = -1;
    int neg = INT_MAX;

    for(auto c : s) {
        if(c == '1') pos = currSize;
        if(c == '0') neg = min(neg,currSize);
        if(c == '+') currSize++;

        if(c == '-') {
            currSize--;
            pos = min(pos, currSize);

            if(neg > currSize) {
                neg = INT_MAX;
            }
        }

        if(neg <= 1 || pos >= neg) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

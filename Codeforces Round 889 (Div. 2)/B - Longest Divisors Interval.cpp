#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int idx = 1;
        while(n%(idx+1) == 0) idx++;

        cout << idx << "\n";
    }

    return 0;
}
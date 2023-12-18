#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> mp;

    int m;
    cin >> m;

    while(m--) {
        int t,x;
        cin >> t >> x;
        if(t == 1) {
            mp[x]++;
            continue;
        }

        bool ok = true;

        int curr = 0;
        for(int i = 0; i < 30;i++) {
            curr += mp[i];
            if((x & (1 << i))) {
                ok &= curr > 0;
                curr--;
            }
            curr /= 2;
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}

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
        int s = 0;
        while(n--) {
            int tmp;
            cin >> tmp;
            s += tmp;
        }
        cout << (s % 2 == 0 ? "YES" : "NO") << "\n";
    }

    return 0;
}
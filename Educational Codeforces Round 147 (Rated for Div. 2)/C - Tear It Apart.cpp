#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;

    int ans = INT_MAX;

    for(char c = 'a'; c <= 'z';c++) {
        int last = -1;
        int biggest = 0;

        for(int i = 0; i < s.size();i++) {
            if(s[i] == c) {
                biggest = max(biggest, i - last - 1ll);
                last = i;
            }
        }

        int tmp = s.size() - last - 1ll;
        biggest = max(biggest, tmp);

        int cnt = 0;
        while(biggest > 0) {
            biggest /= 2;
            cnt++;
        }

        ans = min(ans, cnt);
    }

    cout << ans << "\n";
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

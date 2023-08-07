#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    int cnt = 0;
    for(int i = 1; i <= n;i++) {
        int tmp;
        cin >> tmp;
        if(tmp == i) cnt++;
    }

    cnt++;
    cout <<(cnt / 2) << "\n";
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
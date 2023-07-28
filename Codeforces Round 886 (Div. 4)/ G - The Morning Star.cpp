#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int,int> mp1;
    map<int,int> mp2;
    map<int,int> mp3;
    map<int,int> mp4;

    for(int i = 0; i < n;i++) {
        int a,b;
        cin >> a >> b;
        mp1[a]++;
        mp2[b]++;
        mp3[a-b]++;
        mp4[a+b]++;
    }

    int ans = 0;
    for(auto p: mp1) ans += p.second*(p.second-1);
    for(auto p: mp2) ans += p.second*(p.second-1);
    for(auto p: mp3) ans += p.second*(p.second-1);
    for(auto p: mp4) ans += p.second*(p.second-1);
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
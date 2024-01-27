#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];
    vector<map<int,int>> mp(2);

    int ans = 0;

    for(int i = 0; i < n;i++) {
        int val = k + min(0ll, i - k + 1) + min(0ll, -(i + k - n));
      
        int next = i + k - 1;
        int next2 = k - i - 1;
        if (next < n) mp[next % 2][a[next]]++;
        if (next2 < k - 1 && next2 >= 0) mp[next2 % 2][a[next2]]++;

        int last = i - k;
        int last2 =  n + n - i - k;
        if (last >= 0) mp[last % 2][a[last]]--;
        if (last2 < n) mp[last2 % 2][a[last2]]--;

        ans += val - mp[i%2][a[i]];
    }

    cout << ans/2 << "\n";
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x,k;
    cin >> x >> k;

    vector<pair<int,int>> pairs;
    while(k--) {
        int l;
        cin >> l;

        int cnt = 0, pay = 0;

        while(l--) {
            int tmp;
            cin >> tmp;
            pay = min(pay, cnt);
            cnt += tmp;
            if(cnt > 0) {
                pairs.push_back(make_pair(cnt, pay));
                cnt = 0;
            }
        }
    }

    sort(pairs.begin(), pairs.end(), [](auto e1, auto e2){
        return e1.second > e2.second;
    });

    int ans = x;

    for(auto e: pairs) {
        if(ans + e.second < 0) break;
        ans += e.first;
    }

    cout << ans << "\n";
}

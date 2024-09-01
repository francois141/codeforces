#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()  {
    int n,q;
    cin >> n >> q;

    vector<int> cnt(n+1);
    for(int i = 0; i < n;i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for(int i = 1; i <= n;i++) cnt[i] += cnt[i-1];

    map<int,vector<int>> queries;
    for(int i = 0; i < q;i++) {
        int x;
        cin >> x;
        queries[x].push_back(i);
    }

    vector<int> ans(q);

    for(auto e: queries) {

        int start = 0;
        int end = e.first-1;

        while(start != end) {
            int middle = (start + end) / 2;

            int tmp = 0;
            int j = 0;
            for(; j < cnt.size();j += e.first) {
                tmp += cnt[min(j + middle, (int)cnt.size()-1)];
                if(j - 1 > 0) tmp -= cnt[j-1];
            }

            if(tmp >= (n+2)/2) {
                end = middle;
            } else {
                start = middle+1;
            }
        }

        for(auto idx: e.second) ans[idx] = start;
    }

    for(auto e: ans) cout << e << " ";
    cout << "\n";
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

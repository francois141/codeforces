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

        vector<int> a(n+1);
        vector<int> b(n+1);

        for(int i = 1; i <= n;i++) cin >> a[i];
        for(int i = 1; i <= n;i++) cin >> b[i];
        for(int i = 1; i <= n;i++) a[i] -= b[i];

        set<pair<int,int>> s;
        for(int i = 1; i <= n;i++){
            s.insert({a[i], i});
        }

        set<int> ans;
        for(auto e: s) {
            if(e.first == s.rbegin()->first) {
                ans.insert(e.second);
            }
        }

        cout << ans.size() << "\n";
        for(auto e: ans) cout << e << " ";
        cout << "\n";
    }

    return 0;
}
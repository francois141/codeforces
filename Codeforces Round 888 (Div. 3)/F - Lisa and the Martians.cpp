#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    vector<int> a = vector<int>(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int mask = 0;
    for(int j = k-1; j >= 0; j--) {
        int mask2 = mask | (1 << j);
        set<int> s;
        for(auto e: a) {
            s.insert(e & mask2);
        }
        if(s.size() < a.size()) {
            mask = mask2;
        }
    }

    map<int, vector<int>> mp;
    for(int i = 0; i < a.size();i++) {
        int idx = a[i] & mask;
        mp[idx].push_back(i);
        if(mp[idx].size() > 1) {
            int x = 0;
            for(int j = k-1; j >= 0; j--) {
                int a1 = a[mp[idx][0]];
                int a2 = a[mp[idx][1]];
                if(((a1 >> j) & 0x1) == ((a2 >> j) & 0x1) && (((a1 >> j) & 0x1) == 0))  {
                    x |= (1 << j);
                }
            }

            cout << mp[idx][0]+1 << " " << mp[idx][1]+1 << " " << x << "\n";
            return;
        }
    }
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

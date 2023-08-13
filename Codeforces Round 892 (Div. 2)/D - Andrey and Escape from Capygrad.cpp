#include <bits/stdc++.h>
#define int long long
using namespace std;

struct entry {
    int a,b;
    int l,r;
};

void solve()  {
    int n;
    cin >> n;

    vector<entry> entries(n);
    for(int i = 0; i < n;i++) {
        cin >> entries[i].l;
        cin >> entries[i].r;
        cin >> entries[i].a;
        cin >> entries[i].b;
    }

    sort(entries.begin(), entries.end(), [](auto e1, auto e2){
       return e1.l < e2.l;
    });

    int from = INT_MIN;
    int to = INT_MIN;
    map<int,int> mp;

    for(int i = 0; i < n;i++) {
        auto curr = entries[i];
        if(to < curr.l) {
            // Save to map
            mp[from] = to;
            // Start next
            from = curr.l;
        }

        to = max(to,curr.b);
    }

    mp[from] = to;

    int q;
    cin >> q;

    while(q--) {
        int pos;
        cin >> pos;

        int val = prev(mp.upper_bound(pos))->second;
        cout << max(pos, val) << " ";
    }

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

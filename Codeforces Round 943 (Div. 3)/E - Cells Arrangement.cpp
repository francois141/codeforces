#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    map<int,vector<pair<int,int>>> mp;

    mp[2].push_back({1,1});
    mp[2].push_back({1,2});

    mp[3].push_back({2,1});
    mp[3].push_back({2,3});
    mp[3].push_back({3,1});

    mp[4].push_back({1,1});
    mp[4].push_back({1,3});
    mp[4].push_back({4,3});
    mp[4].push_back({4,4});

    mp[5].push_back({1,1});
    mp[5].push_back({1,3});
    mp[5].push_back({1,4});
    mp[5].push_back({2,1});
    mp[5].push_back({5,5});

    if(n <= 5) {
        for(auto e: mp[n]) {
            cout << e.first << " " << e.second << "\n";
        }
    } else {
        cout << n << " " << 1 << "\n";
        cout << n-2 << " " << 3 << "\n";

        for(int i = n; i > 2;i--) {
            cout << 1 << " " << i << "\n";
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
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    map<int,int> mp;
    for(int i = 0; i < n;i++) {
        int tmp;
        cin >> tmp;
        mp[tmp]++;
    }

    vector<int> values(n+1);

    for(auto e: mp) {
        int idx = 1;
        while(idx * e.first < values.size()) {
            values[idx*e.first] += e.second;
            idx++;
        }
    }

    cout << *max_element(values.begin()+1, values.end()) << "\n";
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
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>
#include <map>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    vector<pair<vector<int>, int>> values(n+1);
    for(int i = 1; i <= n;i++) {
        int x;
        cin >> x;
        values[i] = make_pair(vector<int>(x), i);
        for(int j = 0; j < x;j++) cin >> values[i].first[j];
    }

    sort(values.begin(), values.end(), [](auto e1, auto e2) {
        return e1.first.size() < e2.first.size();
    });

    vector<int> grid(1e6+1, 0);

    for(int idx = 1; idx <= n;idx++) {

        // Check if we find one good
        map<int,int> mp;
        for(auto e: values[idx].first) {
            mp[grid[e]]++;
        }
        mp[0] = 0;

        for(auto p: mp) {
            if(p.second < values[p.first].first.size()) {
                cout << "YES" << "\n";
                cout << values[p.first].second << " " << values[idx].second << "\n";
                return 0;
            }
        }

        // Add new to the grid -  we can simply overwrite
        for(auto e: values[idx].first) grid[e] = idx;
    }

    cout << "NO" << "\n";

    return 0;
}

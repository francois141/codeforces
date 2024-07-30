#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    cout << "YES" << "\n";
    vector<pair<int,int>> answer;

    vector<bool> marked(n, false);
    for(int i = n-1; i >= 1;i--) {
        map<int,int> mp;
        for(int j = 1; j <= n;j++) {
            if(marked[j]) continue;

            int eq = a[j] % i;
            if(mp.find(eq) != mp.end()) {
                answer.push_back({mp[eq], j});
                marked[j] = true;
                break;
            } 

            mp[eq] = j;
        }
    }

    reverse(answer.begin(), answer.end());

    for(auto e: answer) cout << e.first << " " << e.second << "\n";

    return;
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

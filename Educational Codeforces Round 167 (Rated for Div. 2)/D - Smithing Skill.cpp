#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;

    vector<int> a(n); 
    vector<int> b(n);

    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n;i++) cin >> b[i];

    vector<int> mp(1e6+1, INT_MAX);
    
    for(int i = 0; i < n;i++) {
        mp[a[i] - b[i]] = min(mp[a[i] - b[i]], a[i]);
    }

    int ans = 0;
    
    map<int,int> pq;
    pq[0] = 0;

    while(m--) {
        int x; cin >> x;
        pq[x] += 1;
    }

    for(int diff = 1; diff < mp.size(); diff++) {
        int atLeast = mp[diff];

        auto it = pq.rbegin();
        while(it->first >= atLeast) {
            int total = (it->first - atLeast) / diff + 1;

            // Answer += the ratio
            ans += 2 * total * it->second;

            // Update the total
            pq[it->first -  diff * total] += it->second;

            // Don't erase 0
            if(pq.size() > 1) {
                pq.erase(prev(pq.end()));
            }

            it = pq.rbegin();
        }
    }

    cout << ans << "\n";

    return 0;
}

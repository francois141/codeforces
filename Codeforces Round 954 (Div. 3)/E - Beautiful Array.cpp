#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <assert.h>
#include <cmath>
#define int long long 
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    map<int,vector<int>> mp;

    for(int i = 0; i < n;i++) {
        int x;
        cin >> x;
        int eq = x % k;
        int div = x / k;
        mp[eq].push_back(div);
    }

    int ans = 0;
    bool ok = n % 2 == 1;
    for(auto &e: mp) {
        sort(e.second.begin(), e.second.end());
        if(e.second.size() % 2) {
            if(!ok) {
                cout << "-1\n";
                return;
            } else {
                ok = false;
                if(e.second.size() == 1) continue;
                // Compute the best one
                int n = e.second.size();
                vector<int> f1(n),f2(n);
                for(int i = 0; i < n-1;i += 2) f1[i] = e.second[i+1] - e.second[i];  
                for(int i = n-1; i >= 1;i-= 2) f2[i] = e.second[i] - e.second[i-1];
   
                for(int i = 1; i < n;i++) f1[i] += f1[i-1];
                for(int i = n-2; i >= 0;i--) f2[i] += f2[i+1];  
    
                int curr = min(f1[n-3], f2[1]);

                for(int i = 0; i + 3 < n;i+= 2) {
                    curr = min(curr, f1[i] + f2[i+3]);
                }

                ans += curr;
            }
        } else {
            for(int i = 0; i < e.second.size();i += 2) {
                ans += e.second[i+1] - e.second[i];
            }
        }
    }

    cout << ans << "\n";
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

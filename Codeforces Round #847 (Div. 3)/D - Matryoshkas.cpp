#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];
    
    map<int,int> mp;
    for(auto e: a) mp[e]++;

    int currentSize = 0;
    int ans = 0;
    int prev = -1;

    for(auto entry : mp) {
        if(prev == entry.first-1) {
            if(entry.second > currentSize) 
                currentSize = entry.second;
            else if(entry.second < currentSize) {
                ans += currentSize - entry.second;
                currentSize = entry.second;
            }
        } else {
            ans += currentSize;
            currentSize = entry.second;
        }
        prev = entry.first;
    }

    cout << ans + currentSize << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}
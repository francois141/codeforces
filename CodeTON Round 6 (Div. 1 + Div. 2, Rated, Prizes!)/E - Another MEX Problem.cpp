#include <iostream>
#include <map>
#include <vector>
#include <set>
#ifdef ONLINE_JUDGE
    #include <bits/stdc++.h>
#endif
#define int long long
using namespace std;

int n;
int idx = 0;
vector<bool> used;

void clear() {
    used = vector<bool>(n+1, false);
    idx = 0;
}

int add(int x) {
    used[x] = true;
    while(used[idx]) idx++;
    return idx;
}

void solve() {
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];
    
    vector<vector<pair<int,int>>> mexs(n+1);
    for(int i = 1; i <= n;i++) {
        mexs[i].push_back(make_pair(INT_MAX, INT_MAX));
        clear();
        for(int j = i; j <= n;j++) {
            int mex = add(a[j]);
            while(!mexs[mex].empty() && mexs[mex].back().second >= j) mexs[mex].pop_back();
            mexs[mex].push_back(make_pair(i,j));
        }
    }

    for(int i = 1; i <= n;i++) {
        mexs[i].push_back(make_pair(INT_MAX, INT_MAX));
        reverse(mexs[i].begin(),mexs[i].end());
    }
    
    vector<int> dist(n+1, INT_MAX);
    dist[0] = 0;

    for(int i = 1; i <= n;i++) {
        for(int curr = 0; curr <= n;curr++) {
            if(dist[curr] + 1 == i) {
                // Launch search
                for(int k = 1; k <= n;k++) {
                    int code = k ^ curr;
                    if(code > n) continue;
                    while(!mexs[code].empty() && mexs[code].back().first < i) mexs[code].pop_back();

                    if(!mexs[code].empty()) dist[k] = min(dist[k], mexs[code].back().second);
                }
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < dist.size();i++) {
        if(dist[i] != INT_MAX) ans = i;
    }
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
        
    return 0;
}

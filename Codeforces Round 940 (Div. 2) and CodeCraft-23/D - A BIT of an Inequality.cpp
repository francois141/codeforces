#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    vector<vector<pair<int,int>>> pre(n, vector<pair<int,int>>(30, {0,0}));
    vector<vector<pair<int,int>>> suf(n, vector<pair<int,int>>(30, {0,0}));

    for(int i = 0; i < n;i++) {
        for(int j = 0; j < 30;j++) {
            if((a[i] >> j) & 0x1) {
                pre[i][j].first++;
                if(i) {
                    pre[i][j].first += pre[i-1][j].second;
                    pre[i][j].second += pre[i-1][j].first;
                }
            } else {
                pre[i][j].second++;
                if(i) {
                    pre[i][j].first += pre[i-1][j].first;
                    pre[i][j].second += pre[i-1][j].second;
                }
            }
        }
    }

    for(int i = n-1; i >= 0;i--) {
        for(int j = 0; j < 30;j++) {
            if((a[i] >> j) & 0x1) {
                suf[i][j].first++;
                if(i < n-1) {
                    suf[i][j].first += suf[i+1][j].second;
                    suf[i][j].second += suf[i+1][j].first;
                }
            } else {
                suf[i][j].second++;
                if(i < n-1) {
                    suf[i][j].first += suf[i+1][j].first;
                    suf[i][j].second += suf[i+1][j].second;
                }
            }
        }
    }

    int ans = 0;

    for(int i = 1; i < n-1;i++) {
        for(int j = 29; j >= 0;j--) {
            if((a[i] >> j) & 0x1) {
                // Increment answer
                ans += pre[i-1][j].first * suf[i+1][j].second;
                ans += pre[i-1][j].second * suf[i+1][j].first;
                ans += pre[i-1][j].first;
                ans += suf[i+1][j].first;

                break;
            }
        } 
    }
    
    for(int j = 29; j >= 0;j--) {
        if((a.back() >> j) & 0x1) {
            // Increment answer
            ans += pre.back()[j].second;
            break;
        }
    } 

    for(int j = 29; j >= 0;j--) {
        if((a[0] >> j) & 0x1) {
            // Increment answer
            ans += suf[0][j].second;
            break;
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


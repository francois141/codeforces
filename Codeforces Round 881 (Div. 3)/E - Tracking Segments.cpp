#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
vector<pair<int,int>> segs;
vector<int> values;

bool test(int idx) {
    vector<int> mask(n+1);
    for(int i = 1; i <= idx;i++) mask[values[i]]++;
    for(int i = 1; i <= n;i++) mask[i] += mask[i-1]; 

    bool ret = false;
    for(auto e: segs) {
        ret |= (mask[e.second] - mask[e.first-1]) > ((e.second - e.first + 1) / 2);
    }

    return ret;
}

void solve() {
    cin >> n >> m,

    segs = vector<pair<int,int>>(m);
    for(int i = 0; i < m;i++) cin >> segs[i].first >> segs[i].second;

    int q;
    cin >> q;

    values = vector<int>(q+1);
    for(int i = 1; i <= q;i++) cin >> values[i];

    int start = 1;
    int end = q+1;

    while(start != end) {
        int middle = (start + end) / 2;
        if(test(middle)) {
            end = middle;
        } else {
            start = middle+1;
        }
    }

    if(start == q+1) start = -1;
    cout << start << "\n";
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


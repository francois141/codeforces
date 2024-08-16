#include <bits/stdc++.h>
#define int long long
using namespace std;

int sum(int n) {
    return n * (n+1) * (2*n+1) / 6;
}

vector<pair<int,int>> offset;

void solve() {
    int n;
    cin >> n;

    int idx = 1;
    while(offset[idx].second < n) idx++;

    int rem = n - offset[idx].first;

    pair<int,int> inter = {rem, rem};

    int ans = 0;
    while(idx > 0) {
        int base = offset[idx].first;
        ans -= sum(base + inter.first-1);
        ans += sum(base + inter.second);

        idx--;
        inter.first--;

        inter.first = max(inter.first, 0ll);
        inter.second = min(inter.second, idx - 1);
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    offset = vector<pair<int,int>>(1);

    int size = 1;
    for(int i = 1; i <= 1e6;) {
        offset.push_back({i, i+size-1});
        i += size;
        size++;
    }

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}


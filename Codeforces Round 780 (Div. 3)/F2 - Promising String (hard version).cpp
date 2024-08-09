#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
string s;
int offset;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        r+=offset;
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ret += bit[r];
        }
            
        return ret;
    }

    void add(int idx, int delta) {
        idx += offset;
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve() {
    cin >> n;
    cin >> s;
    offset = 0;

    int val = 0;
    for(auto e: s) {
        val += (e == '+') ? +1 : -1;
        offset = max(val, offset);
    }

    vector<FenwickTree> trees(3, FenwickTree(n+1));
    trees[0].add(0, 1);

    int ans = 0;

    int diff = 0;
    for(auto e: s) {
        if(e == '-') diff++;
        else diff--;

        int eq = ((diff % 3) + 3) % 3;

        // Get values
        ans += trees[eq].sum(diff);

        // Update data structure
        trees[eq].add(diff, 1);
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

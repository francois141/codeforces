#include <bits/stdc++.h>
#define int long long
using namespace std;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(int size, int x) : FenwickTree(size) {
        for (size_t i = 0; i < size; i++)
            add(i, x);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve() {
    int m,x;
    cin >> m >> x;

    vector<pair<int,int>> c(m);
    for(int i = 0; i < m;i++) cin >> c[i].first;
    for(int i = 0; i < m;i++) c[i].second = i;

    sort(c.begin(), c.end(), [](auto e1, auto e2){
        return e1.first < e2.first || (e1.first == e2.first && e1.second > e2.second);
    });

    auto tree = FenwickTree(m, x);
    set<pair<int,int>> s;
    for(int i = 0; i < m;i++) {
        s.insert({i, x});
    }

    int ans = 0;
    for(auto e: c) {
        if(tree.sum(e.second-1) >= e.first) {
            while(e.first > 0) {
                auto it = prev(s.lower_bound({e.second,-1}));
                auto curr = *it;
                s.erase(it);
                int v = min(curr.second, e.first);
                e.first -= v;
                curr.second -= v;
                tree.add(curr.first, -v);
                if(curr.second > 0) {
                    s.insert(curr);
                }
            }
            ans++;
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

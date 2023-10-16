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

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int n,m;
vector<int> delta;

int update(int base, int diff) {
    diff = (diff % 26) + 26;
    return (base + diff) % 26;
}

void test(FenwickTree &t1, FenwickTree &t2, int pos, int d) {
    if(pos-1 >= 0 && delta[pos] == 0) t1.add(pos-1,d);
    if(pos+1 < n && delta[pos+1] == 0) t1.add(pos,d);

    if(pos-2 >= 0 && (delta[pos-1] + delta[pos]) % 26 == 0) t2.add(pos-2,d);
    if(pos-1 >= 0 && pos+1 < n && (delta[pos] + delta[pos+1]) % 26 == 0) t2.add(pos-1,d);
    if(pos+2 < n && (delta[pos+1] + delta[pos+2]) % 26 == 0) t2.add(pos,d);
}

void solve() {
    cin >> n >> m;

    string s;
    cin >> s;

    delta = vector<int>(n);
    for(int i = 1; i < n;i++) {
        delta[i] = (s[i] - s[i-1] + 26) % 26;
    }

    FenwickTree t1 = FenwickTree(n);
    FenwickTree t2 = FenwickTree(n);

    for(int i = 0; i < n-1;i++) {
        if(s[i] == s[i+1]) {
            t1.add(i, 1);
        }
    }

    for(int i = 0; i < n-2;i++) {
        if(s[i] == s[i+2]) {
            t2.add(i, 1);
        }
    }

    while(m--) {
        int val;
        cin >> val;

        if(val == 1) {
            int l,r,x;
            cin >> l >> r >> x;
            l--; r--;

            test(t1, t2, l,-1);
            delta[l] = update(delta[l], x);
            test(t1, t2, l,1);

            if(r+1 < n){
                test(t1, t2, r+1,-1);
                delta[r+1] = update(delta[r+1], -x);
                test(t1, t2, r+1,1);
            }

        } else {
            int l,r;
            cin >> l >> r;
            l--; r--;
            if((t1.sum(l,r-1) > 0) || (t2.sum(l,r-2) > 0)) {
                cout << "NO" << "\n";
            } else {
                cout << "YES" << "\n";
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

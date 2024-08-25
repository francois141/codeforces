#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree {
    vector<int> tree;
    int n;

    SegTree(const vector<int> &a) {
        tree = vector<int>(4 * a.size());
        n = a.size();
        build(a, 1,0, a.size()-1);
        return;
    }

    void build(const vector<int> &a, int index, int left, int right) {
        if(left == right) {
            tree[index] = a[left];
        } else {
            int middle = (left + right) / 2;
            build(a, 2*index, left, middle);
            build(a, 2*index+1, middle+1, right);
            tree[index] = tree[2*index] + tree[2*index+1];
        }
    }

    int query(int l, int r) {
        return _query(1, 0, n-1,l,r);
    }

    int _query(int v, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return tree[v];

        int middle = (tl + tr) / 2;
        return _query(2*v, tl, middle, l, r) + _query(2*v+1, middle+1, tr, l, r);
    }

    void update(int pos) {
        return _update(1, 0, n-1, pos);
    }

    void _update(int v, int tl, int tr, int pos) {
        if(tl == tr) {
            tree[v]++;
        } else {
            int middle = (tl + tr) / 2;
            if(pos <= middle) {
                _update(2*v, tl, middle, pos);
            } else {
                _update(2*v+1,middle+1, tr, pos);
            }
            tree[v] = tree[2*v] + tree[2*v+1];
        }
    }
};


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin >> n >> q;

    SegTree tree(vector<int>(2e5+1));

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    vector<int> values(n+1);

    for(int i = 1; i <= n;i++) {
        int start = 1;
        int end = 2e5;

        while(start != end) {
            int middle = (start + end) / 2;
            int nb = tree.query(1, middle);

            if(nb >= a[i] * middle) {
                start = middle+1;
            } else {
                end = middle;
            }
        }

        values[i] = start;
        tree.update(start);
    }

    while(q--) {
        int i,x;
        cin >> i >> x;
        if(values[i] <= x) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}

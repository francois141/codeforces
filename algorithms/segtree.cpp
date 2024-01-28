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

    void update(int pos, int new_val) {
        return _update(1, 0, n-1, pos, new_val);
    }

    void _update(int v, int tl, int tr, int pos, int new_val) {
        if(tl == tr) {
            tree[v] = new_val;
        } else {
            int middle = (tl + tr) / 2;
            if(pos <= middle) {
                _update(2*v, tl, middle, pos, new_val);
            } else {
                _update(2*v+1,middle+1, tr, pos, new_val);
            }
            tree[v] = tree[2*v] + tree[2*v+1];
        }
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

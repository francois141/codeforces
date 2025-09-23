#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <limits>
#include <assert.h>
#define int long long
using namespace std;

template<typename T, typename f = std::plus<T>, T NEUTRAL_ELEMENT = 0>
class SegTree {
public:
    static_assert(f{}(NEUTRAL_ELEMENT, NEUTRAL_ELEMENT) == NEUTRAL_ELEMENT, "Neutral element seems weird");
    static_assert(std::is_invocable_r_v<T, f, T,T>, "Binary operator has wrong type");

    vector<T> tree;
    int n;

    SegTree(int n) {
        this->tree = vector<T>(4 * n);
        this->n = n;
    };

    explicit SegTree(const vector<T> &a) {
        this->tree = vector<T>(4 * a.size());
        this->n = a.size();
        build(a, 1,0, a.size()-1);
    }

    T query(int l, int r) {
        assert(0 <= l && r < n);
        return _query(1, 0, n-1,l,r);
    }

    void update(int pos, T new_val) {
        assert(0 <= pos && pos < n);
        _update(1, 0, n-1, pos, new_val);
    }

private:

    void build(const vector<T> &a, T index, int left, int right) {
        if(left == right) {
            tree[index] = a[left];
        } else {
            int middle = (left + right) / 2;
            build(a, 2*index, left, middle);
            build(a, 2*index+1, middle+1, right);
            tree[index] = f{}(tree[2*index], tree[2*index+1]);
        }
    }

    T _query(int v, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return NEUTRAL_ELEMENT;
        if(l <= tl && tr <= r) return tree[v];

        int middle = (tl + tr) / 2;
        return f{}(_query(2*v, tl, middle, l, r), _query(2*v+1, middle+1, tr, l, r));
    }

    void _update(int v, int tl, int tr, int pos, T new_val) {
        if(tl == tr) {
            tree[v] = new_val;
        } else {
            int middle = (tl + tr) / 2;
            if(pos <= middle) {
                _update(2*v, tl, middle, pos, new_val);
            } else {
                _update(2*v+1,middle+1, tr, pos, new_val);
            }
            tree[v] = f{}(tree[2*v], tree[2*v+1]);
        }
    }
};

template<typename T>
struct min_op {
    constexpr T operator()(const T& a, const T& b) const noexcept {
        return a < b ? a : b;
    }
};

template<typename T>
struct max_op {
    constexpr T operator()(const T& a, const T& b) const noexcept {
        return a > b ? a : b;
    }
};

using PlusSegTree = SegTree<int>;
using MinSegTree = SegTree<int, min_op<int>, std::numeric_limits<int>::max()>;
using MaxSegTree = SegTree<int, max_op<int>, std::numeric_limits<int>::min()>;

void solve() {
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

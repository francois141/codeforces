#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree {
    vector<pair<int,int>> tree;
    int n;

    SegTree(const vector<pair<int,int>> &a) {
        tree = vector<pair<int,int>>(4 * a.size());
        n = a.size();
        build(a, 1,0, a.size()-1);
        return;
    }

    void build(const vector<pair<int,int>> &a, int index, int left, int right) {
        if(left == right) {
            tree[index] = a[left];
        } else {
            int middle = (left + right) / 2;
            build(a, 2*index, left, middle);
            build(a, 2*index+1, middle+1, right);
            tree[index] = min(tree[2*index],tree[2*index+1]);
        }
    }

    pair<int,int> query(int l, int r) {
        return _query(1, 0, n-1,l,r);
    }

    pair<int,int> _query(int v, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return make_pair(INT_MAX, INT_MAX);
        if(l <= tl && tr <= r) return tree[v];

        int middle = (tl + tr) / 2;
        return min(_query(2*v, tl, middle, l, r),_query(2*v+1, middle+1, tr, l, r));
    }
};

struct entry {
    int left;
    int right;
    int prev;
    int last;
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for(int i = 0; i < n;i++) cin >> a[i].first;
    for(int i = 0; i < n;i++) a[i].second = i;

    // Build factor
    SegTree tree(a);

    vector<int> factor(n,1);
    stack<entry> st;
    st.push({0, n-1, -1, -1});

    while(!st.empty()) {
        auto e = st.top();
        st.pop();

        if(e.left > e.right) {
            continue;
        }
        if(e.left == e.right) {
            factor[e.left] = 1;
            continue;
        }

        auto q = tree.query(e.left, e.right);
        st.push(entry{e.left, q.second-1, q.first, q.second});
        st.push(entry{q.second+1, e.right, q.first, q.second});

        factor[q.second] = 1;
        if(e.prev < q.first) {
            factor[q.second] -= (e.right - e.left);
            if(e.last != -1) {
                factor[e.last] += (e.right - e.left);
            }
        }

    }

    // Now perform simulation
    int maxVal = max_element(a.begin(), a.end())->first;
    vector<int> prefix(maxVal+1);

    for(int idx = 0; idx < n;idx++) {
        int element = a[idx].first;

        int prev = 0;
        int curr;
        for(int i = 1; i <= ceil(sqrt(element));i++) {
            curr = ceil((double)element / i);
            prefix[i] += factor[idx] * (curr - prev);
            prev = curr;
        }

        for(int i = curr-1; i >= 1;i--) {
            int pos = ceil((double)element / i);
            int curr = i;
            prefix[pos] += factor[idx] * (curr - prev);
            prev = curr;
        }
    }

    // Output values
    for(int i = 1; i <= maxVal;i++) {
        prefix[i] += prefix[i-1];
        cout << prefix[i] << " ";
    }
    cout << "\n";

    return 0;
}

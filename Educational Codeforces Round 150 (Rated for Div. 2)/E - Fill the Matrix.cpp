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
            tree[index] = max(tree[2*index],tree[2*index+1]);
        }
    }

    pair<int,int> query(int l, int r) {
        return _query(1, 0, n-1,l,r);
    }

    pair<int,int> _query(int v, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return make_pair(0ll,0ll);
        if(l <= tl && tr <= r) return tree[v];

        int middle = (tl + tr) / 2;
        return max(_query(2*v, tl, middle, l, r),_query(2*v+1, middle+1, tr, l, r));
    }
};

struct entry {
    int from;
    int to;
    int h;
};

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for(int i = 0; i < n;i++) cin >> a[i].first;
    for(int i = 0; i < n;i++) a[i].second = i;

    map<int,int> mp;

    stack<entry> st;
    st.push({0,n-1, n});

    SegTree tree(a);

    while(!st.empty()) {
        entry e = st.top();
        st.pop();

        if(e.to <= e.from) continue;

        pair<int,int> until = tree.query(e.from, e.to);

        mp[-(e.to - e.from + 1)] += e.h - until.first;
        
        st.push({e.from, until.second-1, until.first});
        st.push({until.second+1, e.to, until.first});
    }

    int m;
    cin >> m;

    int ans = 0;

    for(auto p: mp) {
        int size = -p.first;
        int nb = min(m / size, p.second);

        ans += (size-1) * nb;
        m -= size * nb;

        if(m > 0 && nb < p.second) {
            ans += m-1;
            m = 0;
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

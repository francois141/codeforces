#include <bits/stdc++.h>
#define int long long
using namespace std;

struct SegTree {
    vector<int> tree;
    int n;

    SegTree() {}

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
            tree[index] = max(tree[2*index],tree[2*index+1]);
        }
    }

    int query(int l, int r) {
        return _query(1, 0, n-1,l,r);
    }

    int _query(int v, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return 0;
        if(l <= tl && tr <= r) return tree[v];

        int middle = (tl + tr) / 2;
        return max(_query(2*v, tl, middle, l, r),_query(2*v+1, middle+1, tr, l, r));
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
            tree[v] = max(tree[2*v],tree[2*v+1]);
        }
    }
};

vector<int> a,b;
int ans;
SegTree tree;
map<int,vector<int>> mp;

void compute(int left, int right) {
    if(left > right) return;

    int maxVal = tree.query(left, right);
    auto v = mp[maxVal];

    auto idx1 = lower_bound(v.begin(), v.end(), left) - v.begin();
    auto idx2 = lower_bound(v.begin(), v.end(), right + 1) - v.begin();

    // Add to answer
    ans += idx2 - idx1;

    // Case first
    if(b[v[idx1]-1] - b[left-1] >= maxVal) {
        compute(left, v[idx1]-1);
    }

    // Case middle
    for(int i = idx1; i < idx2-1;i++) {
        if(b[v[i+1]-1] - b[v[i]] >= maxVal) {
            compute(v[i]+1, v[i+1]-1);
        }
    }

    // Case end
    if(b[right] - b[v[idx2-1]] >= maxVal) {
        compute(v[idx2-1]+1, right); 
    }
} 

void solve() {
    int n,x;
    cin >> n >> x;

    a = vector<int>(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    b = a;
    partial_sum(b.begin(), b.end(), b.begin());

    tree = SegTree(a);

    mp.clear();
    for(int i = 1; i <= n;i++) mp[a[i]].push_back(i);
    
    ans = 0;
    
    compute(1, n);
    
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

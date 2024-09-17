#include <bits/stdc++.h>
#define int long long
using namespace std;

struct query {
    int l,r;
    int idx;
    int ans;
};


class SegmentTree {
private:
    vector<long long> tree, lazy;
    int n;

    void propagate(int node, int start, int end) {
        if (lazy[node] != -1) {  // Lazy value means a pending assignment
            tree[node] = (end - start + 1) * lazy[node];  // Apply the lazy value
            
            // If not a leaf, propagate the lazy value to the children
            if (start != end) {
                lazy[2 * node + 1] = lazy[node];
                lazy[2 * node + 2] = lazy[node];
            }

            // Clear the lazy value for this node
            lazy[node] = -1;
        }
    }

    void assignRange(int node, int start, int end, int l, int r, long long value) {
        propagate(node, start, end);  // Apply any pending updates

        if (start > r || end < l)  // Out of range
            return;

        if (start >= l && end <= r) {  // Completely within range
            lazy[node] = value;  // Mark for lazy update
            propagate(node, start, end);  // Apply the lazy value immediately
            return;
        }

        // Partially in range, propagate further down
        int mid = (start + end) / 2;
        assignRange(2 * node + 1, start, mid, l, r, value);
        assignRange(2 * node + 2, mid + 1, end, l, r, value);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];  // Recompute current node
    }

    long long getSum(int node, int start, int end, int l, int r) {
        propagate(node, start, end);  // Apply any pending updates

        if (start > r || end < l)  // Out of range
            return 0;

        if (start >= l && end <= r)  // Completely within range 
            return tree[node];

        // Partially in range
        int mid = (start + end) / 2;
        return getSum(2 * node + 1, start, mid, l, r) +
               getSum(2 * node + 2, mid + 1, end, l, r);
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, -1);
    }

    void assignRange(int l, int r, long long value) {
        assignRange(0, 0, n - 1, l, r, value);
    }

    long long getSum(int l, int r) {
        return getSum(0, 0, n - 1, l, r);
    }
};

void solve() {
    int n,k,q;
    cin >> n >> k >> q;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];
    for(int i = 1; i <= n;i++) a[i] -= i;

    vector<int> values(n+1);

    multiset<int> s;
    map<int,int> freq;

    for(int i = 1; i <= n;i++) s.insert(0);

    for(int i = 1; i <= n;i++) {
        s.erase(s.find(freq[a[i]]));
        s.insert(++freq[a[i]]);

        if(i >= k) {
            values[i-k+1] = *s.rbegin();

            s.erase(s.find(freq[a[i-k+1]]));
            s.insert(--freq[a[i-k+1]]);
        }
    }

    vector<query> queries(q);
    for(int i = 0; i < q;i++) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end(), [](auto q1, auto q2){
        return q1.l > q2.l;
    });


    // Build tree
    SegmentTree tree = SegmentTree(a.size()-k+1);
    stack<pair<int,int>> st;
    st.push({0, a.size()-k}); 
    int curr = a.size() - k + 1;

    for(auto &q: queries) {

        while(curr > q.l) {
            curr--;
            // First update structure
            int until = curr;
            while(!st.empty() && values[curr] >= st.top().first) {
                until = st.top().second;
                st.pop();
            }

            st.push({values[curr], until});

            // Then assign range
            tree.assignRange(curr, until, values[curr]);
        }

        // Execute the query
        q.ans = k * (q.r - q.l + 1 - k + 1) - tree.getSum(q.l, q.r - k + 1);
    }

    sort(queries.begin(), queries.end(), [](auto q1, auto q2){
        return q1.idx < q2.idx;
    });

    for(auto q: queries) cout << q.ans << "\n";
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

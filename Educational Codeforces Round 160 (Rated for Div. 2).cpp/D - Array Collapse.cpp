#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353;

inline int mult(int a,int b) {return ((a%K)*(b%K)) % K;}
inline int add(int a,int b) {return ((a%K)+(b%K)) % K;}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y & 1) z = mult(z, x);
        x = mult(x, x);
        y >>= 1;
    }
    return z;
}

struct SegTree {
    vector<int> tree;
    int n;

    SegTree(){}

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
            tree[index] = min(tree[2*index],tree[2*index+1]);
        }
    }

    int query(int l, int r) {
        return _query(1, 0, n-1,l,r);
    }

    int _query(int v, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return LLONG_MAX;
        if(l <= tl && tr <= r) return tree[v];

        int middle = (tl + tr) / 2;
        return min(_query(2*v, tl, middle, l, r), _query(2*v+1, middle+1, tr, l, r));
    }
};

int n;
vector<int> a;
unordered_map<int,int> trans;
SegTree tree;

int compute(int from, int to) {
    if(to < from) return 1ll;
    if(from == to) return 2ll;

    int idx = trans[tree.query(from, to)];


    int vLeft = compute(from, idx-1);
    int vRight = compute(idx+1, to);

    int ans = mult(vLeft, vRight);

    int without = 0;
    if(from == 0 && to == n-1) without = 0;
    else if(from == 0) without = vLeft;
    else if(to == n-1) without = vRight;
    else without = add(add(vLeft,vRight), K - 1);

    ans = add(ans, without);

    if(ans < 0 || without < 0) {
        cout << "DEBUG" << endl;
        cout << ans << " " << without << endl;
        cout << from << " " << to << endl;
        cout << vLeft << " " << vRight << endl;
        cout << n-1 << endl;
        cout << idx << endl;
        exit(0);
    }

    return ans;
}

void solve() {
    cin >> n;

    a = vector<int>(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    if(n == 1) {
        cout << 1 << "\n";
        return;
    }

    trans.clear();
    for(int i = 0; i < n;i++) trans[a[i]] = i;

    tree = SegTree(a);

    cout << compute(0, n-1) << "\n";
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

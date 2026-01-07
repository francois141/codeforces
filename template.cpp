#ifdef ONLINE_JUDGE
    #include <bits/stdc++.h>
#endif
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <algorithm>
#include <assert.h>
#include <complex>
#include <queue>
#include <utility>
#include <random>
using namespace std;

const int K = 998244353; // or 1e9 + 7;

inline int mult(int a,int b) { return (a * b) % K; }
inline int add(int a,int b) { return (a + b) % K; }

vector<int> factorial;
vector<int> inv_factorial;

int binpow(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mult(z, x);
        x = mult(x, x);
        y >>= 1;
    }
    return z;
}

int inverse(int a) {
    return binpow(a, K - 2);
}

// Direct modular inverse (precomputed version)
inline int inv(int a) {
    return inverse(a); // could be optimized if precomputed
}

// No longer needed if you use inv_factorial
int divide(int a, int b) {
    return mult(a, inverse(b));
}

int binomial_coefficient(int n, int k) {
    if (k < 0 || k > n) return 0;
    return mult(factorial[n], mult(inv_factorial[k], inv_factorial[n - k]));
}

void computefactorial(int N) {
    factorial = vector<int>(N + 1, 1);
    inv_factorial = vector<int>(N + 1, 1);

    for (int i = 1; i <= N; i++) {
        factorial[i] = mult(i, factorial[i - 1]);
    }

    inv_factorial[N] = inverse(factorial[N]); // compute inverse of N! once
    for (int i = N; i > 0; i--) {
        inv_factorial[i - 1] = mult(inv_factorial[i], i);
    }
}

template<typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename
    T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
    os << '{';
    string sep;
    for (const T &x: v) os << sep << x, sep = ", ";
    return os << '}';
}

template<size_t i, typename T>
ostream &print_tuple_utils(ostream &os, const T &tup) {
    if constexpr (i == tuple_size<T>::value) return os << ")";
    else return print_tuple_utils<i + 1, T>(os << (i ? ", " : "(") << get<i>(tup), tup);
}

template<typename... T>
ostream &operator<<(ostream &os, const tuple<T...> &t) { return print_tuple_utils<0, tuple<T...> >(os, t); }

void dbg_out() { cerr << endl; }

template<typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
    cerr << ' ' << H;
    dbg_out(T...);
}

#ifdef ONLINE_JUDGE
    #define dbg(...)
#else
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);
#endif

using ll = long long;
using ld = long double;
using str = string;
using cd = complex<ld>;

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using ti = tuple<int, int, int>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<ld>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vii = vector<vi>;

vi fill_vi(int n) {
    vi a = vector<int>(n);
    for (int i = 0; i < a.size(); i++) cin >> a[i];
    return a;
}
vi fill_vi1(int n) {
    vi a = vector<int>(n+1);
    for (int i = 1; i < a.size(); i++) cin >> a[i];
    return a;
}

vpi fill_vpiidx(int n) {
    vpi a(n);
    for (int i = 0; i < a.size(); i++) cin >> a[i].first;
    for (int i = 0; i < a.size(); i++) a[i].second = i;
    return a;
}

vpi fill_vpiidx1(int n) {
    vpi a(n+1);
    for (int i = 1; i < a.size(); i++) cin >> a[i].first;
    for (int i = 1; i < a.size(); i++) a[i].second = i;
    return a;
}

vii fill_vii(int n, int m) {
    vii a(n, vi(m));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) cin >> a[i][j];
    }
    return a;
}

vii fill_vii1(int n, int m) {
    vii a(n+1, vi(m+1));
    for (int i = 1; i < a.size(); i++) {
        for (int j = 1; j < a[i].size(); j++) cin >> a[i][j];
    }
    return a;
}

vii fill_variable(int n) {
    vii a(n);
    for(int i = 0; i < n;i++) {
        int x;
        cin >> x;
        a[i] = vi(x);
        for(int j = 0; j < x;j++) cin >> a[i][j];
    }
    return a;
}

vii fill_graph(int n, int m) {
    vii graph(n+1);
    for(int i = 0; i < m;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}

vii fill_tree(int n) {
    return fill_graph(n,n-1);
}

vii fill_tree_parent(int n) {
    vii graph(n+1);
    for(int i = 2; i <=n;i++) {
        int x;
        cin >> x;
        graph[x].push_back(i);
    }
    return graph;
}


template<class T>
using pqg = priority_queue<T, vector<T>, greater<T> >;

#define forn(i,n) for(int i = 0; i < n;i++)
#define fore(i, x) for(auto & i: x)

#define f first
#define s second
#define mt make_tuple
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ins insert
#define lb lower_bound
#define ub upper_bound

#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))

const int MOD = 1000000007;
const char nl = '\n';
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld) -1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

template<class T>
int lwb(vector<T> &a, const T &b) { return (lb(all(a), b) - bg(a)); }

template<class T>
int upb(vector<T> &a, const T &b) { return (ub(all(a), b) - bg(a)); }

template<class t, class u>
bool chmax(t &a, u b) {
    if (a < b) {
        a = b;
        return true;
    } else return false;
}

template<class t, class u>
bool chmin(t &a, u b) {
    if (b < a) {
        a = b;
        return true;
    } else return false;
}

template<class T>
void remDup(vector<T> &v) {
    sort(all(v));
    v.erase(unique(all(v)), end(v));
}

template<class T>
vector<T> presumxor(vector<T> &v2) {
    auto v = v2;
    for (int i = 1; i < v.size(); i++) { v[i] ^= v[i - 1]; }
    return v;
}

template<class T>
vector<T> presum(vector<T> &v2) {
    auto v = v2;
    for (int i = 1; i < v.size(); i++) { v[i] += v[i - 1]; }
    return v;
}

// 1D flatten
template<class T>
int flatten(vector<T> &a) {
    set<T> s(a.begin(), a.end());
    map<T, int> mp;
    int idx = 0;
    for (auto e : s)
        mp[e] = idx++;
    for (auto &e : a)
        e = mp[e];
    return idx;
}

// 2D flatten
template<class T>
int flatten(vector<vector<T>> &a) {
    set<T> s;
    for (auto &v : a)
        s.insert(v.begin(), v.end());
    map<T, int> mp;
    int idx = 0;
    for (auto e : s)
        mp[e] = idx++;
    for (auto &v : a)
        for (auto &e : v)
            e = mp[e];
    return idx;
}

int getMSB(int num) {
    if (num == 0) return -1; // No bits set
    return (int) log2(num);
}


template<typename T, typename f = std::plus<T>, T NEUTRAL_ELEMENT = 0>
class SegTree {
public:
    static_assert(f{}(NEUTRAL_ELEMENT, NEUTRAL_ELEMENT) == NEUTRAL_ELEMENT, "Neutral element seems weird");
    static_assert(std::is_invocable_r_v<T, f, T, T>, "Binary operator has wrong type");

    vector<T> tree;
    int n;

    SegTree(int n) {
        this->tree = vector<T>(4 * n);
        this->n = n;
    };

    explicit SegTree(const vector<T> &a) {
        this->tree = vector<T>(4 * a.size());
        this->n = a.size();
        build(a, 1, 0, a.size() - 1);
    }

    T query(int l, int r) {
        assert(0 <= l && r < n);
        return _query(1, 0, n - 1, l, r);
    }

    void update(int pos, T new_val) {
        assert(0 <= pos && pos < n);
        _update(1, 0, n - 1, pos, new_val);
    }

private:
    void build(const vector<T> &a, T index, int left, int right) {
        if (left == right) {
            tree[index] = a[left];
        } else {
            int middle = (left + right) / 2;
            build(a, 2 * index, left, middle);
            build(a, 2 * index + 1, middle + 1, right);
            tree[index] = f{}(tree[2 * index], tree[2 * index + 1]);
        }
    }

    T _query(int v, int tl, int tr, int l, int r) {
        if (r < tl || tr < l) return NEUTRAL_ELEMENT;
        if (l <= tl && tr <= r) return tree[v];

        int middle = (tl + tr) / 2;
        return f{}(_query(2 * v, tl, middle, l, r), _query(2 * v + 1, middle + 1, tr, l, r));
    }

    void _update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int middle = (tl + tr) / 2;
            if (pos <= middle) {
                _update(2 * v, tl, middle, pos, new_val);
            } else {
                _update(2 * v + 1, middle + 1, tr, pos, new_val);
            }
            tree[v] = f{}(tree[2 * v], tree[2 * v + 1]);
        }
    }
};

template<typename T>
struct min_op {
    constexpr T operator()(const T &a, const T &b) const noexcept {
        return a < b ? a : b;
    }
};

template<typename T>
struct max_op {
    constexpr T operator()(const T &a, const T &b) const noexcept {
        return a > b ? a : b;
    }
};

using PlusSegTree = SegTree<int>;
using MinSegTree = SegTree<int, min_op<int>, std::numeric_limits<int>::max()>;
using MaxSegTree = SegTree<int, max_op<int>, std::numeric_limits<int>::min()>;

class GraphDiameter {
public:
    explicit GraphDiameter(const std::vector<std::vector<int> > &g)
        : graph(g), n(g.size()), visited(n, false) {
    }

    pair<int,int> largest_diameter() {
        for (int i = 0; i < n; ++i) {
            if (!graph[i].empty()) {
                auto [u, tmp11, tmp22] = bfs_farthest(i);
                auto [v, diameter, candidates1] = bfs_farthest(u);
                auto [tmp1, tmp2, candidates2] = bfs_farthest(v);
                return mp(diameter, min(*min_element(all(candidates1)), *min_element(all(candidates2))));
            }
        }

        return mp(-1, -1);
    }

private:
    const std::vector<std::vector<int> > &graph;
    int n;
    std::vector<bool> visited;

    struct Output {
        int u;
        int diameter;
        vector<int> candidates;
    };

    Output bfs_farthest(int start) const {
        std::vector<int> dist(n, -1);
        std::queue<int> q;

        q.push(start);
        dist[start] = 0;


        int far = start;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            far = u;
            for (int v: graph[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        vector<int> candidates;
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] == dist[far])
                candidates.push_back(i);
        }

        return Output{far, dist[far], candidates};
    }
};

string remove_char(const string & s, char c) {
    string output;
    for (auto e: s) {
        if (e != c)
            output.push_back(e);
    }
    return output;
}

int build(int x, int first_value) {
    int ans = 0;
    int base = 1;

    while (x > 0) {
        int tmp = min(x, first_value);
        x -= tmp;
        ans += tmp * base;
        base *= 10;

        first_value = 9;
    }

    return ans;
}

inline int cnt(int x) {
    int ans = 0;
    while (x > 0) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int factor(int x) {
    int ans = 0;
    while(x > 0) {
        ans++;
        x /= 10;
    }
    return ans;
}


class EulerTour {
public:
    int n;
    std::vector<std::vector<int>> adj;

    std::vector<int> tin, tout;
    std::vector<int> euler;
    int timer = 0;

    EulerTour(const vector<vector<int>>& adj)
        : n(adj.size()), adj(adj), tin(adj.size()), tout(adj.size()) {
        build(1);
    }

    bool is_in_subtree(int u, int v) const {
        return tin[v] <= tin[u] && tout[u] <= tout[v];
    }
private:
    void dfs(int v, int parent) {
        tin[v] = timer++;
        euler.push_back(v);

        for (int u : adj[v]) {
            if (u == parent) continue;
            dfs(u, v);
        }

        euler.push_back(v);

        tout[v] = timer++;
    }

    void build(int root = 0) {
        timer = 0;
        euler.clear();
        dfs(root, -1);
    }
};

void print_indices(vii&sets, int x, int y) {
    vector<int> indices;
    for(int i = 0; i < sets.size();i++) {
        int v1 = count(all(sets[i]), x);
        int v2 = count(all(sets[i]), y);
        if(v1 > 0 && v2 > 0)
            indices.push_back(i+1);
    }

    cout << indices[0] << " " << indices[1] << "\n";
}

//  g++ main.cpp -std=c++20 -fsanitize=address -fno-omit-frame-pointer -g && ./a.out < input.txt
void solve() {
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();



#ifndef ONLINE_JUDGE

#endif


    return 0;
}

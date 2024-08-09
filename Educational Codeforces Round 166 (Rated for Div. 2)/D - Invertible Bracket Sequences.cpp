#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>
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
            tree[index] = min(tree[2*index],tree[2*index+1]);
        }
    }

    int query(int l, int r) {
        return _query(1, 0, n-1,l,r);
    }

    int _query(int v, int tl, int tr, int l, int r) {
        if(r < tl || tr < l) return INT_MAX;
        if(l <= tl && tr <= r) return tree[v];

        int middle = (tl + tr) / 2;
        return min(_query(2*v, tl, middle, l, r),_query(2*v+1, middle+1, tr, l, r));
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
            tree[v] = min(tree[2*v],tree[2*v+1]);
        }
    }
};

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    s = " " + s;

    vector<int> prefix(s.size());
    for(int i = 1; i < s.size();i++) {
        if(s[i] == '(') prefix[i]++;
        else prefix[i]--; 
    }

    partial_sum(prefix.begin(), prefix.end(), prefix.begin());

    SegTree tree(vector<int>(s.size(), n));

    map<int,vector<int>> mp;
    for(int i = 0; i <= n;i++) mp[prefix[i]].push_back(i);
    for(auto &p: mp) p.second.push_back(INT_MAX);

    int ans = 0;

    for(int i = s.size()-1; i >= 1;i--) {
        int maxVal = 2*prefix[i-1]+1;
        int until = tree.query(maxVal, n);
        int lvl = prefix[i-1];

        // Now binary search here 
       auto idx1 = upper_bound(mp[lvl].begin(), mp[lvl].end(), i);
       auto idx2 = upper_bound(mp[lvl].begin(), mp[lvl].end(), until-1);

       ans += idx2 - idx1; 

       // Update segment tree
       tree.update(lvl, i);
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

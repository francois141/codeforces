#include <bits/stdc++.h>
#define int long long
using namespace std;

struct query {
    int s;
    int d;
    int k;
    int idx;

    bool operator<(const query &other) {
        return this->d < other.d;
    }
};

void solve() {
    int n,q;
    cin >> n >> q;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    vector<query> queries(q);
    for(int i = 0; i < q;i++) cin >> queries[i].s >> queries[i].d >> queries[i].k;
    for(int i = 0; i < q;i++) queries[i].idx = i;

    sort(queries.begin(), queries.end());

    vector<int> ans(q,0);

    int i = 0;

    vector<int> prefix(n+1);
    vector<int> specialPrefix(n+1);

    for(; i < q && queries[i].d <= sqrt(n); i++) {
        int d = queries[i].d;

        if(i == 0 || queries[i-1].d != queries[i].d) {
            fill(prefix.begin(), prefix.end(), 0);
            fill(specialPrefix.begin(), specialPrefix.end(), 0);
            for(int j = 1; j <= d;j++) {
                for(int k = j; k <= n;k += d) {
                    prefix[k] = a[k] + prefix[max(0ll, k-d)];
                    specialPrefix[k] = ceil(k/(double)d) * a[k] + specialPrefix[max(0ll, k-d)];
                }
            }
        }

        int end = queries[i].s + d * (queries[i].k-1);
        int start = max(queries[i].s - d,0ll);
        ans[queries[i].idx] = specialPrefix[end] - specialPrefix[start] - (prefix[end] - prefix[start]) * (ceil(queries[i].s / (double)d) - 1);
     }

    for(;i < q;i++) {
        int val = 0;
        for(int j = 0; j < queries[i].k;j++) val += (j+1) * a[queries[i].s + j * queries[i].d];
        ans[queries[i].idx] = val;
    }

    for(auto e: ans) cout << e << " ";
    cout << "\n";
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

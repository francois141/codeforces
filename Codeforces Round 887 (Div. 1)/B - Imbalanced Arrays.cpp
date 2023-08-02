#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for(int i = 0; i < n;i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.rbegin(), a.rend());

    vector<int> ans(n);

    int p = n;
    int m = 0;

    int start = 0;
    int end = n-1;

    while(start <= end) {
        int size = end - start + 1;

        bool c1 = a[start].first - m == size && a[end].first - m == 0;
        bool c2 = a[start].first - m != size && a[end].first - m != 0;

        if(c1 || c2) {
            cout << "NO" << "\n";
            return;
        }

        if(a[end].first - m == 0) {
            ans[a[end].second] = -p;
            end--;
        } else {
            ans[a[start].second] = p;
            start++;
            m++;
        }

        p--;
    }

    cout << "YES" << "\n";
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

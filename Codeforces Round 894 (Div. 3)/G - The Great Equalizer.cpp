#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if(n == 1) {
        int q;
        cin >> q;

        while(q--) {
            int i,x;
            cin >> i >> x;
            cout << x << " ";
        }
        cout << "\n";

        return;
    }

    multiset<int> values;
    for (auto e: a) values.insert(e);

    multiset<int> segments;
    auto it = values.begin();
    auto it2 = it;
    ++it2;
    while (it2 != values.end()) {
        segments.insert(*it2 - *it);
        ++it; ++it2;
    }

    int q;
    cin >> q;
    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;
        // Remove
        {
            auto it = values.find(a[i]);
            auto ne = it;
            ++ne;
            auto pe = it;
            --pe;
            if(it == values.begin()) {
                segments.erase(segments.find(*ne - *it));
            } else if(ne == values.end()) {
                segments.erase(segments.find(*it - *pe));
            } else {
                segments.erase(segments.find(*ne - *it));
                segments.erase(segments.find(*it - *pe));
                segments.insert(*ne - *pe);
            }
        }

        values.erase(values.find(a[i]));
        a[i] = x;
        values.insert(a[i]);

        // Add
        {
            auto it = values.find(a[i]);
            auto ne = it;
            ++ne;
            auto pe = it;
            --pe;
            if(it == values.begin()) {
                segments.insert(*ne - *it);
            } else if(ne == values.end()) {
                segments.insert(*it - *pe);
            } else {
                segments.insert(*ne - *it);
                segments.insert(*it - *pe);
                segments.erase(segments.find(*ne - *pe));
            }
        }

        cout << *values.rbegin() + *segments.rbegin() << " ";
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
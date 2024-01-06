#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    int cnt0 = 0;
    bool stop = false;

    vector<pair<int,int>> a;
    for(int i = 0; i < n;i++) {
        int x;
        cin >> x;
        if(x == 0) cnt0++;
        if(x < 0 || cnt0 > 1)stop = true;
        a.push_back({i, x});
    }

    if(stop || cnt0 != 1) {
        cout << "NO" << "\n";
        return;
    }

    sort(a.begin(), a.end(), [](auto e1, auto e2){
        return e1.second < e2.second;
    });

    set<pair<int,int>> se;
    se.insert(a[0]);
    for(int i = 1; i < a.size();i++) {
        se.insert(a[i]);

        bool ok = false;

        auto it = se.find(a[i]);
        if(it != se.begin() && abs((--it)->second-a[i].second) <= 1) ok = true;

        it = se.find(a[i]);
        if(((++it) != se.end()) && (abs((it)->second-a[i].second) <= 1)) ok = true;

        if(!ok) {
            cout << "NO" << "\n";
            return;
        }
    }

    cout << "YES" << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

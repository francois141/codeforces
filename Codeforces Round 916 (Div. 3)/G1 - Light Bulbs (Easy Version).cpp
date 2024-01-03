#include <bits/stdc++.h>
#define int long long
using namespace std;
const int K = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> a(2*n);
    for(int i = 0; i < 2*n;i++) cin >> a[i];

    map<set<int>, int> mp;

    set<int> curr;
    vector<pair<int,int>> intervals;

    mp[curr] = -1;
    for(int i = 0; i < 2*n;i++) {
        if(curr.find(a[i]) != curr.end()) curr.erase(curr.find(a[i]));
        else curr.insert(a[i]);

        if(mp.find(curr) != mp.end()) intervals.push_back({mp[curr]+1, i});
        mp[curr] = i;
    }

    sort(intervals.begin(), intervals.end());

    stack<pair<int,int>> st;
    int nb = 0;
    int ans = 1;

    int current = 1;

    for(auto e: intervals) {
        while(!st.empty() && st.top().second < e.first) st.pop();

        if(st.empty()) {
            st.push(e);
            ans = (ans * current) % K;
            nb++;
            current = e.second - e.first + 1;
        } else if(st.size() == 1) {
            st.push(e);
            current -= e.second - e.first + 1;
        }
    }
    ans = (ans * current) % K;

    cout << nb << " " << ans << "\n";
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

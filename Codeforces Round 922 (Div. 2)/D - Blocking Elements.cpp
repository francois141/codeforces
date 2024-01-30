#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> a;

bool check(int value) {

    vector<int> dp(a.size());

    multiset<int> s;
    s.insert(dp[0]);

    int end = 0;
    for(int i = 1; i <= n;i++) {
        while(a[i-1] - a[end] > value) {
            s.erase(s.find(dp[end]));
            end++;
        }

        dp[i] = (a[i] - a[i-1]) + *s.begin();
        s.insert(dp[i]);
    }

    return dp.back() <= value;
}

void solve() {
    cin >> n;

    a = vector<int>(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    partial_sum(a.begin(), a.end(), a.begin());

    n++;
    a.push_back(a.back());

    int start = 0;
    int end = 1e15;

    while(start != end) {
        int middle = (start + end) / 2;
        if(check(middle)) {
            end = middle;
        } else {
            start = middle + 1;
        }
    }

    cout << start << "\n";
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
vector<int> a;

bool test(int value) {
    vector<int> mask(a.size());
    for(int i = 0; i < a.size();i++) mask[i] = 1 * (a[i] >= value);

    vector<int> dp(a.size());
    for(int i = 0; i < n;i+=k) {
        dp[i] = mask[i];
        if(i > 0) dp[i] = max(dp[i], dp[i-k]);
    }

    int eq = a.size() % k;
    if(eq == 0) eq = k;

    for(int j = 1; j < eq;j++) {
        for(int i = j; i < n; i += k) {
            // Pick here
            dp[i] = mask[i] + dp[i-1];
            // Don't pick here
            if(i - k >= 0) dp[i] = max(dp[i], dp[i-k]);
        }
    }

    int maxVal = 0;
    for(int i = eq-1;i < n;i += k) {
        maxVal = max(maxVal, dp[i]);
    }

    return maxVal > eq / 2;
}

void solve() {
    cin >> n >> k;

    a = vector<int>(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int start = 1;
    int end = *max_element(a.begin(), a.end());

    while(start != end) {
        int middle = (start + end + 1) / 2;
        if(test(middle)) {
            start = middle;
        } else {
            end = middle-1;
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

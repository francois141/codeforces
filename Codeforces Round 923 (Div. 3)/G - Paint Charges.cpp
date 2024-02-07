#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<int> a;
vector<vector<int>> dp;

map<vector<int>, int> cache;

int compute(int from, int to) {
    if(from == to) return 1;
    if(to < from) return 0;
    if(dp[from][to] != -1) return dp[from][to];

    int ans = INT_MAX;

    for(int i = from; i <= to;i++) {
        for(int j = 0; j < a[i];j++) {
            // Left
            ans = min(ans, 1 + compute(from, i - j - 1) + compute(i + 1, to));
            if(i-j-1 <= -3) break;
        }

        for(int j = 0; j < a[i];j++) {
            // Right
            ans = min(ans, 1 + compute(from,i-1) + compute(i+j+1,to));
            if(i+j+1 >= n+2) break;
        }

        // Both of them
        int left = INT_MAX;
        vector<int> right;
        right.push_back(compute(i+1, to));
        for(int j = max(i - a[i] + 1,from); j < i;j++) {
            // Get left
            left =  min(left, compute(from,j-1));
            // Get right
            int ridx = max(0ll, j + a[j] - i);
            while(right.size() <= ridx)  {
                right.push_back(compute(i + right.size(), to));
                if(right.size() >= 2) right.back() = min(right.back(), right[right.size()-2]);
            }
            // Combine
            ans = min(ans, 2 + left + right[ridx]);
        }
    }

    return dp[from][to] = ans;
}

void solve() {
    cin >> n;

    a = vector<int>(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    if(cache.find(a) != cache.end()) {
        cout << cache[a] << "\n";
        return;
    }

    dp = vector<vector<int>>(n,vector<int>(n,-1));

    cache[a] = compute(0,n-1);
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

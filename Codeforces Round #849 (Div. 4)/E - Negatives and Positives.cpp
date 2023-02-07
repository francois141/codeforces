#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n;i++) cin >> a[i];

	vector<pair<int,int>> dp(n);

	dp[0].first = a[0];

	dp[1].first = a[0] + a[1];
	dp[1].second = -a[0] - a[1]; 

	for(int i = 2; i < n;i++) {
		// Pas switch
		dp[i].first = a[i] + max(dp[i-1].first,dp[i-1].second);

		// Switch
		int v1 = -a[i] - 2*a[i-1] + dp[i-1].first;
		int v2 = -a[i] + 2*a[i-1] + dp[i-1].second;

		dp[i].second = max(v1,v2);
	}

	cout << max(dp.back().first,dp.back().second) << "\n";
}	

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--)	
		solve();
}

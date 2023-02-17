#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n+1);
	a[0] = 0;
	for(int i = 1; i <= n;i++) cin >> a[i];
	

	sort(a.begin(),a.end());

	int ans = 0;
	int currSize = 0;
	for(int i = 1; i <= n;i++) {
		if(a[i-1] < a[i] || currSize < a[i]) {
			currSize++;
			ans += a[i] - currSize;
		}
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
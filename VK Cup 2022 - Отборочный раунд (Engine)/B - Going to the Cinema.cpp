#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n;i++) cin >> a[i];

	sort(a.begin(),a.end());
	a.push_back(INT_MAX);

	int ans = 0;

	for(int i = 0; i < n;i++) {
		if(i >= a[i] && i+1 < a[i+1]) {
			ans++;
		} 
	}

	if(a[0] != 0) ans++;

	cout << ans << "\n";
}	

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--)	
		solve();
}

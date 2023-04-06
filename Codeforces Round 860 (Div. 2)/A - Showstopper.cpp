#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n;i++) cin >> a[i];
	for(int i = 0; i < n;i++) cin >> b[i];

	for(int i = 0; i < n;i++) {

		int mini = min(a[i],b[i]);
		int maxi = max(a[i],b[i]);

		a[i] = mini;
		b[i] = maxi;
	}
	
	bool c1 = (a.back() == *max_element(a.begin(),a.end()));
	bool c2 = (b.back() == *max_element(b.begin(),b.end()));

	if(c1 && c2) {
		cout << "YES" << "\n";
	} else {
		cout << "NO" << "\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();
}

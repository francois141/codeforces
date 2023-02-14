#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;

	int c;
	cin >> c;

	vector<int> a(n);
	for(int i = 0; i < n;i++) cin >> a[i];

	for(int i = 0; i < n;i++) a[i] += i+1;

	sort(a.begin(),a.end());

	int idx = 0;
	while(true) {
		if(idx == a.size()) break;
		
		c -= a[idx];
		if(c < 0) break;
		
		idx++;
	}

	cout << idx << "\n";
}	

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--)	
		solve();
}

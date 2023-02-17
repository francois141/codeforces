#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n,w,h;
	cin >> n >> w >> h;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n;i++) cin >> a[i];
	for(int i = 0; i < n;i++) cin >> b[i];
	
	vector<int> mins;
	vector<int> maxs;

	for(int i = 0; i < n;i++) {
		int start = a[i] - w;
		int end = a[i] + w;
		mins.push_back(start - (b[i] - h));
		maxs.push_back(end - (b[i] + h));
	}

	if(*max_element(mins.begin(),mins.end()) <= *min_element(maxs.begin(),maxs.end())) {
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

	return 0;
}
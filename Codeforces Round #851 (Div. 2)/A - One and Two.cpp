#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n);

	int cnt = 0;
	for(int i = 0; i < n;i++) {
		cin >> a[i];

		if(a[i] == 2) cnt++;
	}

	if(cnt% 2 == 1) {
		cout << -1 << "\n";
		return;
	}

	if(cnt == 0) {
		cout << 1 << "\n";
		return;
	}

	cnt /= 2;

	int idx = 0;
	while(cnt) {
		if(a[idx] == 2) cnt--;
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

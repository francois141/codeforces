#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;

	if(n % 2 == 0) {
		cout << "YES" << "\n";
		for(int i = 0; i < n;i++) {
			if(i % 2 == 0) cout << -1 << " ";
			else cout << 1 << " ";
		}
		cout << "\n";
	} else if(n == 3){
		cout << "NO" << "\n";
	} else {
		cout << "YES" << "\n";
		int k = n / 2;
		for(int i = 0; i < n;i++) {
			if(i % 2 == 0) {
				int tmp = -(k-1);
				cout << tmp << " ";
			} else {
				cout << k << " ";
			}
		}
		cout << "\n";
	}

	return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	int t; cin >> t;
	while(t--)
		solve();

    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;

	int current = 0;
	int a = 0;
	int b = 0;

	while(n > 0){
		a += min(current,n);
		n -= min(current,n);
		current++;
		a += min(current,n);
		n -= min(current,n);
		current++;

		b += min(current,n);
		n -= min(current,n);
		current++;
		b += min(current,n);
		n -= min(current,n);
		current++;
	}

	cout << a << " " << b << "\n";
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
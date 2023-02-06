#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int w,d,h;
	cin >> w >> d >> h;

	int a,b,f,g;
	cin >> a >> b >> f >> g;

	int ans = 0;

	ans += abs(a-f) + abs(b-g);
	ans += h;
	ans += min(2*min({f,w-f,g,d-g}),2*min({a,w-a,b,d-b}));

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

#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int x,y;
	x = 0;
	y = 0;

	for(auto c : s) {
		if(c == 'U') y++;
		if(c == 'D') y--;
		if(c == 'L') x--;
		if(c == 'R') x++;
		
		if(x == 1 && y == 1) {
			cout << "YES" << "\n";
			return;
		}
	}

	cout << "NO" << "\n";
	return;
}	

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int t;
	cin >> t;

	while(t--)	
		solve();
}

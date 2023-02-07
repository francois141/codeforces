#include <bits/stdc++.h>

using namespace std;

set<int> s;

void solve() {
	char c;
	cin >> c;

	if(s.find(c) == s.end()) cout << "no" << "\n";
	else cout << "yes" << "\n";
}	

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string tmp = "codeforces";
	for(auto t: tmp) s.insert(t);

	int t;
	cin >> t;

	while(t--)	
		solve();
}

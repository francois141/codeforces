#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	int start = 0;
	int end = s.size()-1;

	while(start <= end) {
		if(s[start] == s[end]) {
			cout << end - start + 1 << "\n";
			return;
		}
		
		start++;
		end--;
	}

	cout << 0 << "\n";
}	

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--)	
		solve();
}

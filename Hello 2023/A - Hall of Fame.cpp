#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n; cin >> n;
	vector<char> c = vector<char>(n);

	int countR = 0;
	int countL = 0;
	for(int i = 0; i <  n;i++) {
		cin >> c[i];
		if(c[i] == 'R') countR++;
		if(c[i] == 'L') countL++;
	}

	bool hasR = false;
	bool hasL = false;

	for(int i = 0; i < n;i++) {
		if(!hasR && c[i] == 'R') {
			hasR = true;
			continue;
		}
		if(hasR && c[i] == 'L') { 
			hasL = true;
		}
	}

	if(countR == 0||countL == 0)  {
		cout << -1 << "\n"; 
		return;
	} 

	if(hasL) {
		cout << 0 << "\n";
		return;
	}

	for(int i = 0; i < n-1;i++) {
		if(c[i] == 'L' && c[i+1] == 'R') {
			cout << i+1 << "\n";
		}
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

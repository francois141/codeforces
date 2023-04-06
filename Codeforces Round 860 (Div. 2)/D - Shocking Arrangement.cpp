#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;

	int s = 0;
	int z = 0;

	vector<int> pos(0);
	vector<int> neg(0);
	
	for(int i = 0; i < n;i++) {
		int tmp;
		cin >> tmp;
		s += abs(tmp); 
		if(tmp == 0)  z++;
		else if(tmp > 0) pos.push_back(tmp);
		else neg.push_back(tmp);
	}

	if(s == 0) {
		cout << "NO" << "\n";
		return;
	}

	cout << "Yes" << "\n";

	for(int i = 0; i < z;i++) cout << 0 << " ";

	int curr = 0;
	curr += pos.back();
	
	cout << pos.back() << " ";
	pos.pop_back();
	
	while(!pos.empty() || !neg.empty()) {
		if(curr > 0) {
			curr += neg.back();
			cout << neg.back() << " ";
			neg.pop_back();
		} else {
			curr += pos.back();
			cout << pos.back() << " ";
			pos.pop_back();
		}
	}
	cout << "\n";;

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

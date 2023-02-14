#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n;
	cin >> n;

	if(n % 2 == 0) {
		cout << "No" << "\n";
		return;
	}

	vector<pair<int,int>> ans;

	ans.push_back(make_pair(1,2*n));

	for(int i = 2; i < n;i+=2) {
		ans.push_back(make_pair(i,n+(n+1)/2 - i/2));
	}

	int s = 3;
	int c = n*2-1;
	for(int i = n*2-1; i > n;i-=2) {
		ans.push_back(make_pair(c ,s));
		c--;
		s+=2;
	}

	cout << "Yes" << "\n";
	for(auto p: ans) {
		cout << p.first << " " << p.second << "\n";
	}

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

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int m;
	cin >> m;

	vector<vector<int>> a(m+1, vector<int>(0));

	map<int,int> occ2;

	for(int i = 1; i <= m;i++) {
		int n;
		cin >> n;
		a[i] = vector<int>(n);
		for(int j = 0; j < n;j++) {
			cin >> a[i][j];
			occ2[a[i][j]] = i;
		}
	}


	vector<pair<int,int>> occ;
	for(auto e : occ2) {
		occ.push_back(make_pair(e.second,e.first));
	}

	sort(occ.begin(),occ.end());



	vector<int> ans(0);

	int c = 0;
	for(int i = 1; i <= m;i++) {
		while(occ[c].first < i) c++;

		if(occ[c].first == i) {
			ans.push_back(occ[c].second);
		} else {
			cout << -1 <<"\n";
			return;
		}
	}

	for(auto e: ans)
		cout << e << " ";
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();
}

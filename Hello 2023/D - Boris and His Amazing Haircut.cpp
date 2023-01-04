#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n; cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n;i++) cin >> a[i];
	for(int i = 0; i < n;i++) cin >> b[i];

	int m; cin >> m;
	vector<int> sizes(m);
	for(int i = 0; i < m;i++) cin >> sizes[i];

	for(int i = 0; i < n;i++) {
		if(a[i] < b[i]) {
			cout << "NO" << "\n";
			return;
		}
	}

	stack<int> s;
	map<int,int> mp;

	for(int i = 0; i < n;i++) {

		while(!s.empty() && s.top() < b[i]) {
			s.pop();
		}

		if(a[i] == b[i]) continue;

		if(s.empty() || s.top() > b[i]) {
			s.push(b[i]);		
			mp[b[i]]++;
		} 
	}

	for(auto s:sizes) {
		mp[s]--;
	}

	for(auto k: mp) {
		if(k.second > 0) {
			cout << "NO" << "\n";
			return;
		}
	}

	cout << "YES" << "\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n,c;
	cin >> n >> c;

	vector<pair<int,int>> a(n);
	for(int i = 0; i < n;i++) {
		int tmp;
		cin >> tmp;
		a[i] = make_pair(tmp + min(i+1,n-i),tmp+i+1);
	} 

	sort(a.begin(),a.end());

	vector<int> b;
	b.push_back(0);

	for(int i = 0; i < n;i++) {
		b.push_back(b.back()+a[i].first);
	}

	int ans = 0;
	for(int i = 0; i < n;i++) {
		int cost = c - a[i].second;

		int start = 0;
		int end = n;

		while(start <= end) {
			int middle = (start + end) / 2;
			int currentCost = b[middle];
			int size = middle+1;

			if(middle > i) {
				size--;
				currentCost -= a[i].first;
			}

			if(currentCost <= cost) {
				ans = max(ans,size);
				start = middle+1;
			} else {
				end = middle-1;
			}
		}
	}

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

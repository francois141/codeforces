#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n,k;
	cin >> n >> k;

	priority_queue<int, vector<int>, greater<int> > queue;

	vector<int> a(n);
	for(int i = 0; i < n;i++) {
		cin >> a[i];
		queue.push(a[i]);
	}

	int ans = 0;

	int counter = 0;
	
	for(int i = 0; i < n;i++) {
		if(a[i] == queue.top()) {
			queue.pop();
			continue;
		}
		counter++;
	}

	int add = counter % k;
	counter = counter / k;
	if(add >= 1) counter++;

	cout << counter << "\n";
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

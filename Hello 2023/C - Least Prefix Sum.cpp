#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;
int n, m;

int getVal1()
{
	int count = 0;
	priority_queue<int> q;
	int sum = 0;
	for (int i = m + 1; i < a.size(); i++)
	{
		if (a[i] < 0) q.push(abs(a[i]));

		sum += a[i];
		while (sum < 0)
		{
			sum += 2 * q.top();
			q.pop();
			count++;
		}
	}
	return count;
}

int getVal2()
{
	int count = 0;
	priority_queue<int> q;
	int sum = 0;
	for (int i = m; i >= 1; i--)
	{
		if (a[i] > 0)
			q.push(a[i]);
		sum += a[i];
		while (sum > 0)
		{
			sum -= 2 * q.top();
			q.pop();
			count++;
		}
	}
	return count;
}

void solve()
{

	cin >> n >> m;
	m--;

	a = vector<int>(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	if (n == 1)
	{
		cout << 0 << "\n";
		return;
	}

	cout << getVal1() + getVal2() << "\n";

	return;
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()
{
	int n;
	cin >> n;

	map<int,int> mp;

	vector<pair<int,int>> a(n);

	for(int i = 0; i < n;i++) {
		cin >> a[i].first;
        a[i].first--;
        a[i].second = i;
		mp[a[i].first]++;
	}

	if(n == 1) {
		cout << "YES" << "\n" << 1 << "\n" << 1 <<"\n";
		return;
	}

	sort(a.begin(),a.end(), [](auto p1, auto p2){
        return p1.first < p2.first;
    });

	for(auto key: mp) {
		if(key.second > 2) {
			cout << "NO" << "\n";
			return;
		}
	}

	for(int i = n-1;i >= 0;i--) {
		if(a[i].first < i) {
			cout << "NO" << "\n";
			return;
		}
	}

    // Construct the good assignemement
	vector<vector<int>> ans(n,vector<int>(2,-1));

    vector<bool> free1(n,true);
    vector<bool> free2(n,true);

    priority_queue<pair<int,int>> q1;
    priority_queue<pair<int,int>> q2;

    for(int i = n-1; i >= 0;i--) {
        if(free1[a[i].first]) {
            ans[a[i].second][0] = a[i].first;
            free1[a[i].first] = false;
            q2.push(make_pair(a[i].first,a[i].second));
        } else {
            ans[a[i].second][1] = a[i].first;
            free2[a[i].first] = false;
            q1.push(make_pair(a[i].first,a[i].second));
        }
    }
    
    priority_queue<int> rem1;
    priority_queue<int> rem2;
    for(int i = 0; i < n;i++) {
        if(free1[i]) rem1.push(i);
        if(free2[i]) rem2.push(i);
    }

    while(!q1.empty()) {
        int val = rem1.top();
        rem1.pop();
        auto k = q1.top();
        q1.pop();
        ans[k.second][0] = val; 
    }

    while(!q2.empty()) {
        int val = rem2.top();
        rem2.pop();
        auto k = q2.top();
        q2.pop();
        ans[k.second][1] = val; 
    }

	cout << "YES" << "\n";
	for(auto p:ans) cout << p[0]+1 << " ";
	cout << "\n";
	for(auto p:ans) cout << p[1]+1 << " ";
	cout << "\n";
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

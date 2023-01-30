#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 3*1e5+10;
vector<int> lp(N+1);
vector<int> pr;

void sieve() {
	for (int i=2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; i * pr[j] <= N; ++j) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i]) {
				break;
			}
		}
	}
}

set<int> getPrimeDecomposition(int n) {
	set<int> ans;
	while(lp[n] != 0) {
		ans.insert(lp[n]);
		n /= lp[n];
	} 
	if(n != 1) ans.insert(n); 
	return ans;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for(int i = 0; i < n;i++) cin >> a[i];

	int s,t;
	cin >> s >> t;
	s--; t--;

	sieve();

	vector<set<int>> decompositions(0);
	for(auto e: a) decompositions.push_back(getPrimeDecomposition(e));

	map<int,vector<int>> graph;
	for(int i = 0; i < n;i++) {
		for(auto e : decompositions[i]) {
			graph[e].push_back(i);
		}
	}

	vector<bool> visitedPrime(3e5,false);
	vector<bool> visited(n,false);
	vector<int> prev(n,-1);

	queue<int> q;
	q.push(s);
	prev[s] = s;

	while(!q.empty()) {
		auto idx = q.front();
		q.pop();
		visited[idx] = true;

		for(auto p: decompositions[idx]) {
			if(!visitedPrime[p]) {
				visitedPrime[p] = true;
				for(auto next : graph[p]) {
					if(!visited[next]) {
						visited[next] = true;
						q.push(next);
						prev[next] = idx; 
					}
				}
			}
		}
	}

	if(prev[t] == -1) {
		cout << -1 << "\n";
	} else {
		vector<int> ans(0);
		int curr = t;
		while(prev[curr] != curr) {
			ans.push_back(curr);
			curr = prev[curr];
		}
		ans.push_back(s);
		reverse(ans.begin(),ans.end());
		cout << ans.size() << "\n";
		for(auto e : ans) cout << e+1 << " ";
		cout << "\n";
	}

	return 0;
}
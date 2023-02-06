#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<vector<int>> graph;
vector<int> dist;
int min_distance;


void solve() {
	int n,c0;
	cin >> n >> c0;

	vector<int> c(n-1);
	for(int i = 0; i < n-1;i++) cin >> c[i];

	vector<vector<int>> graph = vector<vector<int>>(n+1,vector<int>(0));
	for(int i = 0; i < n-1;i++) {
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	vector<int> dist = vector<int>(n+1,INT_MAX);
	min_distance = INT_MAX;


	function<void(int,int,int)> dfs = [&](int idx, int d, int p){
		if(d < dist[idx] && d < min_distance) {
			dist[idx] = d;
			for(auto e: graph[idx]) {
				if(e != p && d+1 < min_distance)
					dfs(e,d+1,idx);
			}
		}
	};

	dfs(c0,0,-1);

	for(auto val : c) {
		min_distance = min(min_distance,dist[val]);
		cout << min_distance << " ";
		dfs(val,0,-1);
	}
	cout << "\n";
} 

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();
}

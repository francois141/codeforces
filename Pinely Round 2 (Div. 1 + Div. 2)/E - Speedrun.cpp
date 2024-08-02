#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <assert.h>
#include <cmath>
#define int long long
using namespace std;

vector<int> h;
vector<vector<int>> graph;

set<pair<int,pair<int,int>>> s;
vector<bool> visited;
vector<pair<int,int>> dp;

int maxDepth = 0;

pair<int,int> dfs(int curr) {
    if(visited[curr]) return dp[curr];
    visited[curr] = true;
    auto p = make_pair(0, h[curr]);

    for(auto e: graph[curr]) {
        auto ret = dfs(e);

        if(h[curr] > h[e]) ret.first++;          
        if(ret.first > p.first) p = ret;
        else if (ret.first == p.first && ret.second > p.second) p = ret;
    }

    return dp[curr] = p;
}

void solve() {
    int n,m,k;
    cin >> n >> m >> k;

    h = vector<int>(n+1);
    for(int i = 1; i<= n;i++) cin >> h[i];

    graph = vector<vector<int>>(n+1);
    for(int i = 0; i < m;i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    s.clear();
    maxDepth = 0;   
    visited = vector<bool>(n+1, false);
    dp = vector<pair<int,int>>(n+1, {-1,-1});
    int cnt = 0;
    for(int i = 1; i <= n;i++) {
        if(!visited[i]) {
            auto p = dfs(i);
            s.insert({p.first, {h[i], p.second}});
            maxDepth = max(maxDepth, (int)p.first);
        }
    }

    vector<pair<int,pair<int,int>>> s3;
    for(auto e: s) {
        s3.push_back({e.second.second, {e.first, e.second.first}});
    }

    sort(s3.begin(), s3.end());

    pair<int,int> w = {INT_MAX, INT_MAX};
    set<pair<int,int>> s2;
    for(auto e: s) {
        w = min(make_pair(-e.first, e.second.first), w);
    }

    while(s2.size() > 1) s2.erase(prev(s2.end()));
    
    int answer = LLONG_MAX;
    while(!s3.empty()) {
        int current = (-w.first-1) * k + (k - w.second) + s3.back().first;
        w = min(w, make_pair(-s3.back().second.first-1, s3.back().second.second));
        s3.pop_back();
        answer = min(answer, current);
    }
    cout << answer << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

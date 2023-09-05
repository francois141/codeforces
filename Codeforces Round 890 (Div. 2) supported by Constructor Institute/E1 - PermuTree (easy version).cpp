#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>> graph;
int ans = 0;

int dfs(int curr, int p = -1) {
    vector<int> sizes;

    for(auto e: graph[curr]) {
        if(e != p) {
            sizes.push_back(dfs(e, curr));
        }
    }

    bitset<5001> b;
    b[0] = true;

    for(auto e :sizes) {
        b |= (b << e);
    }

    int sum = accumulate(sizes.begin(), sizes.end(), 0ll);
    int idx = sum / 2;

    while(idx) {
        if(b[idx]) {
            ans += idx * (sum - idx);
            break;
        }
        idx--;
    }

    return 1 + sum;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    graph = vector<vector<int>>(n+1);
    for(int i = 2; i <= n;i++) {
        int tmp;
        cin >> tmp;
        graph[i].push_back(tmp);
        graph[tmp].push_back(i);
    }

    dfs(1);

    cout << ans << "\n";

    return 0;
}

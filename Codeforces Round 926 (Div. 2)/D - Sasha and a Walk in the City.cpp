#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; // or 1e9 + 7;

inline int mult(int a,int b) {return ((a%K)*(b%K)) % K;}
inline int add(int a,int b) {return ((a%K)+(b%K)) % K;}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y & 1) z = mult(z, x);
        x = mult(x, x);
        y >>= 1;
    }
    return z;
}

int inverse(int a) {
    return binpow(a,K-2);
}

int divide(int a, int b) {
    return mult(a,inverse(b));
}

vector<vector<int>> graph;
int ans;

int dfs(int curr, int p = -1) {

    // Perform dfs
    vector<int> val;
    for(auto child: graph[curr]) {
        if(child == p) continue;
        val.push_back(dfs(child, curr));
    }

    int tmp = 1;
    for(auto e: val) tmp = mult(tmp, e);

    ans = add(ans, tmp);

    return 1 + tmp;
}

void solve() {
    int n;
    cin >> n;

    graph = vector<vector<int>>(n+1);

    for(int i = 0; i < n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ans = 1; 

    dfs(1,-1);

    cout << ans << "\n";
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

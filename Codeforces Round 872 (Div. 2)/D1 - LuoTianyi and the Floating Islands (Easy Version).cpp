#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 1e9 + 7;

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

int total = 0;

pair<int,int> dfs(int curr, int parent = -1) {
    vector<pair<int,int>> val;

    pair<int,int> out = {1,1};

    vector<pair<int,int>> outputs;

    for(auto next : graph[curr]) {
        if(next == parent) continue;
        auto res = dfs(next, curr);
        // Compute total first
        // Add simple path
        outputs.push_back(res);
        out.second += res.second;
        out.first += res.first + res.second;
    }

    for(auto e: outputs) {
        total = add(total, mult(e.first, out.second - e.second));
    }


    return out;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin >> n >> k;

    graph = vector<vector<int>>(n+1);

    for(int i = 0; i < n-1;i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if(k == 1 || k == 3) {
        cout << 1 << "\n";
    } else {
        dfs(1);
        total = add(total, n*(n-1)/2);
        cout << divide(total, n*(n-1) / 2) << "\n";
    }
}

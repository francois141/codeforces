#include <bits/stdc++.h>
#define int long long
using namespace std;
const int K = 998244353;

inline int add(int x, int y) {
    return (x + y) % K;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; 
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    int size = 310;
    int offset = 300*300; 
    vector<vector<int>> dp(size,vector<int>(2*size*size,0));

    dp[2][a[2] + offset] = 1;

    for(int i = 2; i < n;i++) {
        for(int j = -offset; j <= offset;j++) {
            dp[i+1][a[i+1] + j + offset] = add(dp[i+1][a[i+1] + j + offset],dp[i][j+offset]);
            if(j != 0) 
                dp[i+1][a[i+1] - j + offset] = add(dp[i+1][a[i+1] - j + offset],dp[i][j+offset]);
        }
    }

    cout << accumulate(dp[n].begin(),dp[n].end(),0ll,[](int i1,int i2) {
        return add(i1,i2);
    }) << "\n";
}

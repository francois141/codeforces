#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 1e9 + 7;

inline int mult(int a,int b) {return ((a%K)*(b%K)) % K;}
inline int add(int a,int b) {return ((a%K)+(b%K)) % K;}

vector<int> factorial;
vector<vector<int>> colors;

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

int binomial_coefficient(int n, int k) {
    return divide(factorial[n], mult(factorial[k],factorial[n - k]));
}

vector<int> a;
int n,k;

const int maxn = 5e3;
int C[maxn + 1][maxn + 1];

int check(int l, int r) {
    int c = colors[a[r]][r] - colors[a[r]][l-1];
    return (c < k) ? 0 : C[c-1][k-1];
}

void solve() {
    cin >> n >> k;

    a = vector<int>(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    colors = vector<vector<int>>(n+1, vector<int>(n+1));

    for(int i = 1; i <= n;i++) {
        for(int j = 1; j <= n;j++) {
            colors[i][j] = colors[i][j-1] + (a[j] == i ? 1 : 0);
        }
    }

    vector<pair<int,int>> dp(n+1,{0,0});
    dp[0] = {0,1};

    int maxVal = 0;

    for(int i = 1; i <= n;i++) {
        for(int j = 1; j <= i;j++) {
            int c = check(j, i);
            if(c > 0) {
                if(dp[j-1].first + 1 < dp[i].first) continue;
                if(dp[j-1].first + 1 == dp[i].first) dp[i].second = add(dp[i].second, mult(c, dp[j-1].second));
                if(dp[j-1].first + 1 > dp[i].first) dp[i] = {dp[j-1].first+1, mult(c,dp[j-1].second)};
            }
        }

        maxVal = max(maxVal, dp[i].first);
    }

    int ans = 0;
    for(auto e : dp) {
        if(e.first == maxVal) {
            ans = add(ans, e.second);
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    C[0][0] = 1;
    for (int n = 1; n <= maxn; ++n) {
        C[n][0] = C[n][n] = 1;
        for (int k = 1; k < n; ++k)
            C[n][k] = (C[n - 1][k - 1] + C[n - 1][k]) % K;
    }

    int t;
    cin >> t;

    while(t--)
        solve();
}

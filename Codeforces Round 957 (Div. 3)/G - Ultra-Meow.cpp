#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>
#define int long long 
using namespace std;

const int K = 1e9 + 7;

const int maxn = 5e3+15;
int C[maxn + 1][maxn + 1];


inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}

int binomial_coefficient(int n, int k) {
    if(n < 0 || k < 0) return 0;
    if(k > n) return 0;
    return C[n][k];
}

void solve() {
    int n;
    cin >> n;

    int ans = 0;

    for(int i = 0; i < (n+1)/2;i++) {
        for(int a = 1; a <= 2*i+1; a++) {
            int space = a-1;
            int before = a - i - 1;

            int left = n - a;
            int after = i - before;

            int mu = mult(binomial_coefficient(space, before),binomial_coefficient(left, after));
            ans = add(ans, mult(a, mu));
        }
    }

    for(int i = (n+1)/2; i <= n;i++) {
        ans = add(ans, mult(binomial_coefficient(n, i), 2*i+1));
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

    return 0;
}

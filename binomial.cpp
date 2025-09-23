#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#define int long long
using namespace std;

const int K = 998244353; // or 1e9 + 7;

inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}

vector<int> factorial;
vector<int> inv_factorial;

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

// Direct modular inverse (precomputed version)
inline int inv(int a) {
    return inverse(a); // could be optimized if precomputed
}

// No longer needed if you use inv_factorial
int divide(int a, int b) {
    return mult(a,inverse(b));
}

int binomial_coefficient(int n, int k) {
    if(k < 0 || k > n) return 0;
    return mult(factorial[n], mult(inv_factorial[k], inv_factorial[n-k]));
}

void solve() {
    // Example: compute C(5,2)
    cout << binomial_coefficient(5,2) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N = 1e6;
    factorial = vector<int>(N+1,1);
    inv_factorial = vector<int>(N+1,1);

    for(int i = 1; i <= N; i++) {
        factorial[i] = mult(i, factorial[i-1]);
    }

    inv_factorial[N] = inverse(factorial[N]); // compute inverse of N! once
    for(int i = N; i > 0; i--) {
        inv_factorial[i-1] = mult(inv_factorial[i], i);
    }

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

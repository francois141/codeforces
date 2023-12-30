#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; // or 1e9 + 7

inline int mult(int a,int b) {return ((a%K)*(b%K)) % K;}
inline int add(int a,int b) {return ((a%K)+(b%K)) % K;}

vector<int> factorial;

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

void solve() {
    int n,k;
    cin >> n >> k;

    int base_size = n / (2*k);
    int rem = n % (2*k);

    int ans = base_size * (base_size - 1) / 2;
    ans *= 2*k;
    ans += base_size * rem;

    int cnt = 0;


    for(int i = max(0ll, rem - k - 1); i <= min(rem/2, k-1); i++) {
        int v1 = binomial_coefficient(k-1,i);
        int v2 = binomial_coefficient(k+1-i, rem-2*i);
        int tmp = mult(v1, v2);
        cnt = add(cnt, tmp);
    }

    if(ans == 0) {
        cnt = binomial_coefficient(k-1, n-k-1);
    }


    cout << ans << " " << cnt << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    factorial = vector<int>(1e6+1,1);
    for(int i = 1; i <= 1e6;i++) {
        factorial[i] = mult(i, factorial[i-1]);
    }

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    
    return 0;
}

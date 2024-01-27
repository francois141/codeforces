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

void solve() {
    int n,m,k;
    cin >> n >> m >> k;

    int s = 0;
    for(int i = 0; i < m;i++) {
        int a,b,f;
        cin >> a >> b >> f;
        s += f;
    }

    int size = n * (n - 1) / 2;
    int ans  = mult(k, divide(s, size));

    for(int i = k-1;i > 0;i--) {
        int tmp = mult(i, mult(divide(m,size),divide(1,size)));
        ans = add(ans, tmp);
    }

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

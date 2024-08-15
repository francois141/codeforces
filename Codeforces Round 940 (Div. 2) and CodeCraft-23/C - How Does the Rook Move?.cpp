#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 1e9 + 7;

inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}

vector<int> factorial;
vector<int> factorial2;

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

    while(k--) {
        int a,b;
        cin >> a >> b;
        if(a == b) n--;
        else n -= 2;
    }

    int ans = 0;
    for(int i = 0; i <= n;i += 2) {
        ans = add(ans, mult(binomial_coefficient(n, i), factorial2[i]));
    }
    
    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    factorial = vector<int>(1e6+1,1);
    factorial2 = vector<int>(1e6+1,1);
    factorial2[1] = 2;
    for(int i = 2; i <= 1e6;i++) {
        factorial[i] = mult(i, factorial[i-1]);
        if(i & 0x1 && i >= 3) factorial2[i] = mult(2*factorial2[i-2], i);
        else factorial2[i] = factorial2[i-1];
    }

    int t;
    cin >> t;
    
    while(t--)
        solve();

    return 0;
}


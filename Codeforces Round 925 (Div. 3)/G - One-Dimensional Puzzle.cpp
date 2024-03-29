#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; // or 1e9 + 7;

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

int compute(int q, int size) {
    return binomial_coefficient(size+q-1, q);
}

void solve() {
    int v1,v2,v3,v4;
    cin >> v1 >> v2 >> v3 >> v4;

    if(abs(v1 - v2) > 1) {
        cout << 0 << "\n";
        return;
    }

    if(v1 == 0 && v2 == 0) {
        cout << (v3 != 0 && v4 != 0 ? 0 : 1) << "\n";
        return;
    }

    int answer = 0;
    if(v1 == v2) {
        int size = v1;
        answer = add(answer, mult(compute(v3,size),compute(v4,size+1)));
        answer = add(answer, mult(compute(v3,size+1),compute(v4,size)));
    } else {
        int size = max(v1,v2);
        answer = mult(compute(v3, size),compute(v4, size));
    }

    cout << answer << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    factorial = vector<int>(4e6+1,1);
    for(int i = 1; i <= 4e6;i++) {
        factorial[i] = mult(i, factorial[i-1]);
    }

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

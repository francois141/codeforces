#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; // or 1e9 + 7

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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    for(int i = n;i >= 1;i--) {
        int m = 2;
        while(i*m <= n) {
            a[i] = max(a[i], a[i*m]);
            m++;
        }
    }

    sort(a.begin()+1, a.end());

    int ans = 0;
    for(int i = 1; i <= n;i++) {
        ans = add(ans,mult(a[i],binpow(2, i-1)));
    }

    cout << ans << "\n";

    return 0;
}

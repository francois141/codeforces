#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 1e9 + 7;

inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}

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

void solve() {
    int l,r,k;
    cin >> l >> r >> k;

    if(k <= 9) {
        int val = 9 / k + 1;
        int top = binpow(val, r - l) - 1;
        int low = binpow(val, l);
        cout << mult(top, low) << "\n";

    } else {
        cout << 0 << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

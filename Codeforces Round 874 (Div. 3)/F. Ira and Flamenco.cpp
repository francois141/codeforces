#include <bits/stdc++.h>
using namespace std;
#define int long long
const int K = 1e9 + 7;

inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}

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
    int n,m;
    cin >> n >> m;

    map<int,int> mp;
    for(int i = 0; i < n;i++) {
        int tmp;
        cin >> tmp;
        mp[tmp]++;
    }

    vector<pair<int,int>> freq;
    for(auto e: mp) {
        freq.push_back(e);
    }

    if(m == 1) {
        cout << n << "\n";
        return;
    }

    int ans = 0;

    int p = freq[0].second;

    int start = 0;
    int end = 0;

    while(start < freq.size()-1) {
        start++;
        if(freq[start].first == freq[start-1].first + 1) {
            p = mult(p,freq[start].second);
            if(start - end == m) {
                p = divide(p,freq[end].second);
                end++;
            }
            if(start - end == m-1) {
                ans = add(ans, p);
            }
        } else {
            p = freq[start].second;
            end = start;
        }
    }

    cout << ans << "\n";
}

signed main() {
    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; 

inline int mult(int a,int b) {return ((a%K)*(b%K)) % K;}

vector<int> factorial;

void solve() {
    string s;
    cin >> s;

    vector<int> blocks;

    int curr = 1;
    for(int i = 1; i < s.size();i++) {
        if(s[i] == s[i-1]) {
            curr++;
        } else {
            blocks.push_back(curr);
            curr = 1;
        }
    }

    blocks.push_back(curr);

    int size = 0;
    for(auto e: blocks) size += e-1;

    int ans = factorial[size];
    for(auto e: blocks) ans = mult(ans, e);

    cout << size << " " << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    factorial = vector<int>(2e5+1,1);
    for(int i = 1; i <= 2e5;i++) {
        factorial[i] = mult(i, factorial[i-1]);
    }

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

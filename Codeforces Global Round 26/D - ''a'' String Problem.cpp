#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <assert.h>
#include <cmath>
#define int long long
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    z[0] = s.size();
    return z;
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    if(all_of(s.begin(), s.end(), [](char ch) { return ch == 'a'; })) {
        cout << s.size()-1 << "\n";
        return;
    }

    int idx = 0;
    while(s[idx] == 'a') {
        idx++;
    }

    s.erase(0,idx);

    auto z_value = z_function(s);

    n = s.size();
    vector<int> ne(n);
    vector<int> prev(n);

    int acc = idx;
    for(int i = 0; i < n;i++) {
        if(s[i] == 'a') {
            acc++;
        } else {
            prev[i] = acc;
            acc = 0;
        }
    }

    acc = INT_MAX;
    for(int i = n-1; i >= 0;i--) {
        if(s[i] != 'a') acc = i;
        ne[i] = acc;
    }

    int ans = 0;
    for(int i = 1; i <= n;i++) {
        bool ok = true;
        int maxVal = INT_MAX;

        for(int j = 0; j < n;) {
            maxVal = min(maxVal, prev[j]);
            ok &= (z_value[j] >= i);
            if(j + i < n) {
                int last = j;
                j = ne[j + i];
                maxVal = min(maxVal, j - last - i);
            } else {
                ok &= (j + i == n);
                break;
            }
        }

        if(ok) {
            ans += (maxVal + 1);
        }
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

#include <bits/stdc++.h>
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
    z[0] = INT_MAX;
    return z;
}

int test(vector<int> &z, int value) {
    int idx = 0;
    int cnt = 0;
    while(idx < z.size()) {
        if(z[idx] >= value) {
            cnt++;
            idx += value;
        } else {
            idx++;
        }
    }

    return cnt;
}

void solve() {
    int n,l,r;
    cin >> n >> l >> r;

    string s;
    cin >> s;

    auto z = z_function(s);

    int start = 0;
    int end = s.size() / l;

    while(start != end) {
        int middle = (start + end + 1) / 2;
        if(test(z, middle) >= l) {
            start = middle;
        } else {
            end = middle-1;
        }
    }

    cout << start << "\n";
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

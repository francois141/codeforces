#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<vector<int>> a(n, vector<int>(10));
    for(int i = 0; i < s.size();i++) {
        int val = s[i] - '0';
        a[i][val]++;
        if(i > 0) {
            for(int j = 0; j <= 9;j++) a[i][j] += a[i-1][j];
        }
    }

    reverse(a.begin(), a.end());

    int carry = 0;
    vector<char> ans;

    for(int i = 0; i < s.size();i++) {
        int val = carry;
        for(int j = 0; j <= 9;j++) val += j * a[i][j];
        ans.push_back('0' + (val % 10));
        carry = val / 10;
    }

    while(carry > 0) {
        ans.push_back('0' + (carry % 10));
        carry /= 10;
    }   

    while(!ans.empty() && ans.back() == '0') ans.pop_back();

    reverse(ans.begin(), ans.end());
    for(auto e: ans) cout << e;
    cout << "\n";
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


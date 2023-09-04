#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string ans = "";

    if(k % 2 == 1) {
        multiset<char> s1;
        multiset<char> s2;
        
        for(int i = 0; i < s.size();i+=2) {
            s1.insert(s[i]);
            if(i+1 < s.size()) s2.insert(s[i+1]);
        }

        while(!s1.empty() || !s2.empty()) {
            ans += *s1.begin();
            s1.erase(s1.begin());
            if(!s2.empty()) {
                ans += *s2.begin();
                s2.erase(s2.begin());
            }
        }
    } else {
        ans = s;
        sort(ans.begin(), ans.end());
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
}

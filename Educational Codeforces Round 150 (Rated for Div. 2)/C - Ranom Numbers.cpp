#include <bits/stdc++.h>
#define int long long 
using namespace std;

int val(char c) {
    return pow(10ll, c - 'A');
}

void solve() {
    string s;
    cin >> s;

    vector<int> sum(s.size()+1,0);
    vector<char> big(s.size()+1,0);

    for(int i = s.size()-1; i >= 0; i--) {
        if(big[i+1] <= s[i]) sum[i] = sum[i+1] + val(s[i]);
        else sum[i] = sum[i+1] - val(s[i]);
        big[i] = max(big[i+1], s[i]);
    }

    int ans = LLONG_MIN;    
    int cond = 0;
    map<char, int> mp;
    for(int i = 0; i < s.size();i++) {
        for(char c = 'A'; c <= 'E';c++) {
            int curr = 0;

            char biggest = max(c, big[i+1]);

            for(auto p: mp) {
                if(p.first < biggest) curr -= p.second * val(p.first);
                else curr += p.second * val(p.first);
            }

            int tmp = curr + val(c) + sum[i+1] - cond;
            ans = max(ans, tmp);
        }

        mp[s[i]]++;
        for(auto p: mp) {
            if(p.first < s[i]) {
                cond += val(p.first) * p.second;
                mp[p.first] = 0;
            }
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
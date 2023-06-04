#include <bits/stdc++.h>
#define int long long
using namespace std;

#define NO {cout << "NO" << "\n"; return;}
#define YES {cout << "YES" << "\n"; return;}

bool same(string s1, string s2) {
    vector<int> o(26);
    for(auto c: s1) o[c-'a']++;
    for(auto c: s2) o[c-'a']--;

    return all_of(o.begin(),o.end(),[](auto x) {
        return x == 0;
    });
}

void solve() {
    int n,k;
    cin >> n >> k;

    string s,t;
    cin >> s >> t;

    if(s.size() <= 3) {
        if(s == t) YES
        NO
    }

    if(s.size() == 4) {
        if(s == t) YES
        swap(s[0],s.back());

        if(s == t) YES
        NO
    } 

    if(s.size() == 5) {
        if(s[2] != t[2]) NO
        if(same( s.substr(0,2) + s.substr(3,2),  t.substr(0,2) + t.substr(3,2)))YES
        NO
    } 

    for(int i = 0; i < s.size();i++) {
        if(same(s,t)) YES
        NO
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

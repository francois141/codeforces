#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    cin >> n >> q;

    string s;
    cin >> s;

    set<int> s2;

    for(int i = 0; i < s.size()-1;i++) {
        if(s[i] == s[i+1]) s2.insert(i); 
    }

    bool c1 = (s.size() % 2) == 0;

    while(q--) {
        int pos;
        cin >> pos;
        pos--;

        // Remove
        if(pos > 0 && s[pos-1] == s[pos]) s2.erase(s2.find(pos-1));
        if(pos < s.size()-1 && s[pos] == s[pos+1]) s2.erase(s2.find(pos));

        // Change
        if(s[pos] == '(') {
            s[pos] = ')';
        } else {
            s[pos] = '(';
        }

        // Add again
        if(pos > 0 && s[pos-1] == s[pos]) s2.insert(pos-1);
        if(pos < s.size()-1 && s[pos] == s[pos+1]) s2.insert(pos);
        
        bool ok = c1;
        ok &= s[0] == '(';
        ok &= s.back() == ')';

        if(!s2.empty()) {
            ok &= s[*s2.begin()]  == '(';
            ok &= s[*s2.rbegin()] == ')';
        }

        if(ok) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}

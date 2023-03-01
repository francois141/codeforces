#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string a,b;
    cin >> a >> b;

    if(a[0] == b[0]) {
        cout << "YES" << "\n";
        cout << a[0] << "*" << "\n";
        return;
    }

    if(a.back() == b.back()) {
        cout << "YES" << "\n";
        cout << "*" << a.back() << "\n";
        return;
    }

    set<string> s;
    for(int i = 0; i < a.size()-1;i++) s.insert(a.substr(i,2));

    for(int i = 0; i < b.size()-1;i++) {
        if(s.find(b.substr(i,2)) != s.end()) {
            cout << "YES" << "\n";
            cout << "*" << b.substr(i,2) << "*" << "\n";
            return;
        }
    }
    
    cout << "NO" << "\n";


    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

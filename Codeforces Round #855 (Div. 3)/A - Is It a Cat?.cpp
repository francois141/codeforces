#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    s.erase( unique( s.begin(), s.end() ), s.end() );

    if(s == "meow") {
        cout << "YES\n";
    }
    else {
        cout << "NO" << "\n";
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

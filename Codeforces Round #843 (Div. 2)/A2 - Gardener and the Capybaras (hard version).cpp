#include <bits/stdc++.h>
#define int long
using namespace std;

void solve() {
    string s;
    cin >> s;

    for(int i = 1; i < s.size()-1;i++) {
        if(s[i] == 'a') {
            cout << s.substr(0,i) << " " << s[i] << " " << s.substr(i+1,s.size()-i-1) << "\n";
            return;
        }
    }

    cout << s[0] << " " << s.substr(1,s.size()-2)<< " " << s.back() << "\n";

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
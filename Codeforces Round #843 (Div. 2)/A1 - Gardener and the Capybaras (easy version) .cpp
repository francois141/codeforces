#include <bits/stdc++.h>
#define int long
using namespace std;

void solve() {
    string s;
    cin >> s;

    for(int i = 1; i < s.size()-1;i++) {
        for(int j = 1; i + j < s.size();j++) {
            string s1 = s.substr(0,i);
            string s2 = s.substr(i,j);
            string s3 = s.substr(i+j,s.size()-i-j);

            if((s2.compare(s1) <= 0 && s2.compare(s3) <= 0) || (s2.compare(s1)>= 0 && s2.compare(s3) >= 0)) {
                cout << s1 << " " << s2 << " " << s3 << "\n";
                return;
            } 
        }
    }
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
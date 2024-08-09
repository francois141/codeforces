#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;

    pair<int,int> ans = {0,0};

    for(int i = 0; i < n;i++) {
        string s;
        cin >> s;

        int total = count(s.begin(), s.end(), '1');

        {
            int forced = 0;

            for(int j = 0; j < m-1;) {
                if(s[j] == '1' && s[j+1] == '1') {
                    forced++;
                    j += 2;
                } else {
                    j++;
                }
            }

            ans.first += total - min(forced, m/4);
        }
        {
            int forced = m / 4;

            for(int j = 0; j < m-1;) {
                if(s[j] == '1' && s[j+1] == '1') {
                    j++;
                } else {
                    forced--;
                    j += 2;
                }
            }

            ans.second += total - max(forced, 0ll);
        }
    } 

    cout << ans.first << " " << ans.second << "\n";

    return 0;
}

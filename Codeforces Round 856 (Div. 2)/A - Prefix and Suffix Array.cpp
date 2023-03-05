#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<string> arr(n,"");

    int i = 0;
    for(; i < 2*n-2;i++) {
        string s;
        cin >> s;

        int l = s.length();

        if(arr[l] == "") {
            arr[l] = s;
        } else {
            reverse(s.begin(),s.end());
            if(s != arr[l]) {
                i++;
                cout << "NO" << "\n";
                for(; i < 2*n-2;i++) {
                    string tmp;
                    cin >> tmp;
                }
                    
                return;
            }
        }
    }

    cout << "YES" << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

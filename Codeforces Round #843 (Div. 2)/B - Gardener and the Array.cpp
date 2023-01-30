#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n; cin >> n;

    unordered_map<int,int> s;
    unordered_map<int,int> v;

    vector<int> ans(n,0);
    int c = 0;
    
    for(int i = 0; i < n;i++) {
        cin >> ans[i];
        for(int j = 0; j < ans[i];j++) {
            int tmp; 
            cin >> tmp;
            s[tmp]++;
            v[c++] = tmp;
        }
    }

    c = 0;
    for(auto a : ans) {
        
        bool ok = true;

        for(int i = 0; i < a;i++) {
            if(s[v[c+i]] == 1) {
                ok = false;
            }
        }

        c += a;
        if(ok) {
            cout << "Yes" <<"\n";
            return;
        }
    }


    cout << "No" << "\n";
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
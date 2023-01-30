#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> perm(n,vector<int>(n-1));

    for(int i = 0; i < n;i++) {
        for(int j = 0; j < n-1;j++) {
            cin >> perm[i][j];
        }
    }

    vector<int> ans(0);
    vector<int> taken(n+1,false);

    set<int> s;
    for(int i = 0; i < n;i++) {
        if(s.find(perm[i][0]) == s.end()) {
            s.insert(perm[i][0]); 
        } else {
            ans.push_back(perm[i][0]);
            taken[ans.back()] = true;
            break;
        }
    } 

    for(int j = 0; j < n-1;j++) {
        for(int i = 0; i < n;i++) {
            if(!taken[perm[i][j]]) {
                ans.push_back(perm[i][j]);
                taken[ans.back()] = true;
                break;
            }
        }
    }

    for(auto e: ans) cout << e << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}
#include <bits/stdc++.h>
using namespace std;

vector<int> sol;
vector<int> sol2;

bool comp() {
    for(int i = 0; i < sol.size();i++) {
        if(sol2[i] > sol[i]) 
            return true;
        if(sol[i] > sol2[i])
            return false;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    if(n == 1) {
        cout << a[0] << "\n";
        return;
    }

    int r;
    if(a[0] == n) {
        r = find(a.begin(),a.end(), n-1) - a.begin() - 1;
    } else {
        r = find(a.begin(),a.end(), n) - a.begin() - 1;
    }

    if(r == n-2) {
        r = n-1;
    } 

    int l = r;
    sol.clear();
    for(int i = r+1;i < n;i++) sol.push_back(a[i]);
    for(int i = r; i >= l;i--) sol.push_back(a[i]);
    for(int i = 0; i < l;i++)  sol.push_back(a[i]);

    for(int l = r-1; l >= 0;l--) {
        sol2.clear();
        for(int i = r+1;i < n;i++) sol2.push_back(a[i]);
        for(int i = r; i >= l;i--) sol2.push_back(a[i]);
        for(int i = 0; i < l;i++)  sol2.push_back(a[i]);
        if(comp()) {
            sol = sol2;
        }
    }

    for(auto e: sol) {
        cout << e << " ";
    } cout << "\n";
}

signed main() {
    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
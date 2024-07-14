#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;
#define int long long

int digits(int x) {
    return to_string(x).length();
}


void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> ans;

    for(int a = 1; a <= 10000;a++) {
        int val = n * a;

        int d = digits(val); 
        int d_n = digits(n); 

        int b = d_n * a - d;
        int keep = d_n * a - b;

        string a_s = "";
        string n_s = to_string(n);

        int idx = 0;
        while(a_s.size() < keep) {
            a_s += n_s[idx % n_s.size()];
            idx++;
        }

        while(a_s.size() >= digits(val - b)) {
            if(b != 0 && stoi(a_s) == val-b) {
                ans.push_back({a,b});
            }

            b++;
            a_s.pop_back();
        }
    }

    cout << ans.size() << endl;
    for(auto e: ans) cout << e.first << " " << e.second << "\n";
    return;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}

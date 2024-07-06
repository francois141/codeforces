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


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;

    vector<pair<int,int>> ans(n);
    vector<int> ans2(n);
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n;i++) cin >> a[i].first;
    for(int i = 0; i < n;i++) a[i].second = i;

    sort(a.rbegin(), a.rend());

    cout << "YES" << "\n";
    int pos = 0;
    int side = 1;
    for(int i = 0; i < n;i++) {
        ans[a[i].second] = make_pair(i+1, pos+1);
        if(a[i].first > 0) {
            pos += side*(a[i].first - 1);
            side *= -1;
        }
    }

    for(auto e: ans) cout << e.first << " " << e.second << "\n";

    for(int i = 0; i < n;i++) {
        if(a[i].first == 0) {
            ans2[a[i].second] = a[i].second+1;
        } else {
            ans2[a[i].second] = a[i+1].second+1;
        }
    } 

    for(auto e: ans2) cout << e << " ";
    cout << "\n";

    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

	vector<int> a(n);
    for(int i = 0; i < n;i++) {
        cin >> a[i];
        a[i]--;
    } 

    vector<bool> visited(n,false);
    vector<int> component(n);
    iota(component.begin(),component.end(),0);

    for(int i = 0; i < n;i++) {
        if(!visited[i]) {
			int curr;
            visited[curr = i] = true;
            while(!visited[a[curr]]) {
                component[a[curr]] = component[curr];
                visited[curr = a[curr]] = true;
            }
        }
    }

    set<int> s;
    for(auto c : component) s.insert(c);
    int ans = n - s.size();

    bool found = false;
    for(int i = 0; i < n-1 ;i++) {
        if(component[i] == component[i+1])
            found = true;
    }

    if(found) {
        cout << ans - 1 << "\n";
    } else {
        cout << ans + 1 << "\n";
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

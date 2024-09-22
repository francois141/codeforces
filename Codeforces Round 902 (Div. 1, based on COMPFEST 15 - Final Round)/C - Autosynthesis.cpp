#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int>> graph;
vector<int> deg;
vector<int> color;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    deg = vector<int>(n+1);
    color = vector<int>(n+1,-1);

    graph = vector<vector<int>>(n+1);
    for(int i = 1; i <= n;i++) {
        graph[i].push_back(a[i]);
        deg[a[i]]++;
    }

    bool ok = true;

    // Part 1 visit sides
    stack<int> st;
    for(int i = 1; i <= n;i++) {
        if(deg[i] == 0) st.push(i);
    }

    while(!st.empty()) {
        int curr = st.top();
        st.pop();

        // Unvisited ==> set 0
        if(color[curr] == -1) {
            color[curr] = 0;
            color[a[curr]] = 1;
        } 

        deg[a[curr]]--;
        if(deg[a[curr]] == 0) st.push(a[curr]);
    }

    // Part 2 visit center
    for(int i = 1; i <= n;i++) {
        if(deg[i] != 0 && color[i] != -1) {
            int idx = i;
            while(deg[idx] != 0) {
                color[a[idx]] = max(1 - color[idx], color[a[idx]]);
                deg[idx] = 0;
                idx = a[idx];
            }
        }
    }

    // CORRECT
    for(int i = 1; i <= n;i++) {
        if(color[i] == -1) {
            color[i] = 0;
            int idx = i;
            while(deg[idx] != 0) {
                if(color[a[idx]] == color[idx]) ok = false;
                color[a[idx]] = 1 - color[idx];
                deg[idx] = 0;
                idx = a[idx];
            }
        }
    }

    int cnt = count(color.begin(), color.end(), 0);

    if(!ok ||  cnt < (n+1) / 2) {
        cout << -1 << "\n";
        return 0;
    }

    cout << cnt << "\n";
    for(int i = 1; i <= n;i++) {
        if(color[i] == 0) {
            cout << a[i] << " ";
        }
    }
    cout << "\n";
}

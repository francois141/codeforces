    #include <bits/stdc++.h>
    #define int long long
    using namespace std;
     
    void solve() {
        int n,m;
        cin >> n >> m;
     
        vector<int> a = vector<int>(n);
        vector<int> b = vector<int>(m);
     
        for(int i = 0; i < n;i++) cin >> a[i];
        for(int i = 0; i < m;i++) cin >> b[i];
     
        priority_queue<int, vector<int>, greater<int> > queue;
     
        for(int i = 0; i < n;i++) 
            queue.push(a[i]);
     
        for(int i = 0; i < m;i++) {
            queue.pop();
            queue.push(b[i]);
        }
        int sum = 0;
        while(!queue.empty()) {
            sum += queue.top();
            queue.pop();
        }
        cout << sum << "\n";
    }
     
    signed main() {
     
        ios_base::sync_with_stdio(false);
        cin.tie(0);
     
        int t;
        cin >> t;
     
        while(t--) {
            solve();
        }
    }

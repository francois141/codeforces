#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    priority_queue<int, vector<int>, greater<int> > min_pq;
    priority_queue<int> pq;

    int size = 0;

    for(int i = 1; i <= n;i++) {
        pq.push(a[i]);

        if(!min_pq.empty() && !pq.empty() && pq.top() > min_pq.top()) {
            int tmp = min_pq.top();
            int tmp2 = pq.top();
            pq.pop();
            min_pq.pop();

            pq.push(tmp);
            min_pq.push(tmp2);
        } 

        if(pq.top() > size) {
            size++;
            min_pq.push(pq.top());
            pq.pop();
        }
    
        cout << size << " "; 
    }

    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

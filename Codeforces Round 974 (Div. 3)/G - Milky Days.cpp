#ifdef ONLINE_JUDGE
    #include <bits/stdc++.h>
#endif

#include <iostream>
#include <vector>
#include <stack>

#define int long long
using namespace std;

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n;i++) cin >> a[i].second >> a[i].first;

    stack<pair<int,int>> st;
    st.push({0, INT_MIN});
    
    int ans = 0;
    int pos = 0;

    for(int i = 0; i < n;i++) {
        st.push(a[i]);
        pos = a[i].second;

        while(st.top().second + k - 1 >= pos) {
            int until = min((i < n-1) ? a[i+1].second : INT_MAX, st.top().second + k);

            int canDo = min(until - pos, st.top().first / m);
            ans += canDo;
            pos += canDo;

            st.top().first -= canDo * m;

            if(pos == until) {
                if(st.top().first == 0) st.pop();
                break;
            } else {
                int left = m;
                while(left > 0 && st.top().second + k - 1 >= pos) {
                    int rem = min(left, st.top().first);
                    left -= rem;
                    st.top().first -= rem;
                    if(st.top().first == 0) st.pop();
                }
                
                if(left == 0) {
                    ans++;
                    pos++;
                }
            }
        }
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}
G - Milky Days

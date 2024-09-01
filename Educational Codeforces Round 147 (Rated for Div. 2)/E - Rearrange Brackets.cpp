#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve()  {
    int k;
    cin >> k;

    string s;
    cin >> s;

    int n = s.size();
    s = " " + s;

    int acc = 0;

    int tmp = 0;
    for(int i = 1; i <= n;i++) {
        if(s[i] == '(') {
            acc += tmp;
            tmp++;
        } else {
            tmp--;
        }
    }

    vector<int> pre(n+1);
    for(int i = 1; i <= n;i++) {
        pre[i] = pre[i-1];
        if(s[i] == '(') pre[i]++;
    }

    stack<int> st;
    vector<int> ans;
    for(int i = 1; i <= n;i++) {
        if(s[i] == '(') {
            st.push(i);
        } else {
            ans.push_back(pre[i] - pre[st.top()]);
            st.pop();
        }
    }

    sort(ans.rbegin(), ans.rend());
    for(int i = 0; i < min((int)ans.size(), k);i++) acc -= ans[i];

    cout << acc<< "\n";
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

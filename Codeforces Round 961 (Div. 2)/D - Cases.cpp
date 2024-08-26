#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,c,k;
    cin >> n >> c >> k;

    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    vector<int> until(c,-1);

    vector<bool> mask((1 << c) + 1);
    for(int i = 0; i < n;i++) {
        until[s[i] - 'A'] = i + k - 1;

        int val = 0;
        for(int j = 0; j < c;j++) {
            if(until[j] >= i) val += (1ll << j);
        }

        mask[val] = true;
    }

    vector<bool> visited((1ll << c) + 1, 0);
    for(int i = 1; i < (1ll << c);i++) {
        if(mask[i]) {
            stack<int> values;
            values.push(~i & ((1ll << c)-1));

            while(!values.empty()) {
                int v = values.top();
                values.pop();

                if(visited[v]) continue;
                visited[v] = true;

                for(int j = 0; j < c;j++) {
                    if((v & (1 << j)) != 0) values.push(v - (1 << j));
                }
            }
        }
    }

    int ans = INT_MAX;
    for(int i = 1; i < (1ll << c);i++) {
        if(!visited[i]) {
            ans = min(ans, (int)__builtin_popcountll(i));
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
}

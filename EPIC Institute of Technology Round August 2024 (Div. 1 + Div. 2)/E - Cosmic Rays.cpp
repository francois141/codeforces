#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> stack;
    for(int i = 0; i < n;i++) {
        pair<int,int> e;
        cin >> e.second >> e.first;

        int currMax = 0;
        while(!stack.empty() && (e.second > stack.back().second || e.first == stack.back().first)) {
            if(stack.back().first == e.first) {
                e.second += stack.back().second - currMax;
                currMax = 0;
            } else {
                currMax = stack.back().second;
            }

            stack.pop_back();
        }

        stack.push_back(e);
        cout << stack[0].second << " ";
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

    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    deque<int> a;
    for(int i = 0; i < n;i++) {
        int x; cin >> x;
        a.push_back(x);
    }

    deque<pair<int,int>> q;

    int currMin = a.back();
    int size = 1;
    int currVal = 0;

    for(int i = n-2;i >= 0;i--) {
        if(a[i] < currMin) {
            currVal += currMin * size;
            q.push_front({currMin, size});
            // Reset
            size = 1;
            currMin = a[i];
        } else {
            size++;
        }
    }

    currVal += currMin * size;
    q.push_front({currMin, size});

    int ans = currVal;

    for(int i = 0; i < n-1;i++) {
        // Update q
        q.front().second--;
        if(q.front().second == 0) q.pop_front();

        // Update a
        a.push_back(a.front());
        a.pop_front();


        int tmpSize = 1;
        int val = a.back();

        while(true) {
            if(q.empty() || q.back().first < val) break;
            currVal -= q.back().first * q.back().second;
            tmpSize += q.back().second;
            q.pop_back();
        }

        q.push_back(make_pair(val, tmpSize));

        currVal += tmpSize * val;
        ans = max(ans, currVal);
    }

    cout << ans + n << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

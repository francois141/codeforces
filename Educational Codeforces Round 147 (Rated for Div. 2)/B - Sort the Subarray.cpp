#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n;i++) cin >> b[i];

    int minVal = INT_MAX;
    int maxVal = -1;

    for(int i = 0; i < n;i++) {
        if(a[i] != b[i]) {
            minVal = min(minVal, i);
            maxVal = max(maxVal, i);
        }
    }

    while(minVal > 0 && b[minVal] >= a[minVal-1]) {
        minVal--;
    }
    while(maxVal < n-1 && b[maxVal] <= a[maxVal+1]) {
        maxVal++;
    }

    cout << minVal+1 << " " << maxVal+1 << "\n";
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

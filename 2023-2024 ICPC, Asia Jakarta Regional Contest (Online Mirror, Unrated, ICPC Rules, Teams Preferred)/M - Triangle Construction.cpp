#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int max_val = *max_element(a.begin(), a.end());
    int sum = accumulate(a.begin(), a.end(), 0ll);

    cout << min(sum / 3, sum - max_val) << "\n";
}

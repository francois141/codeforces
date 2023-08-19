#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;

bool test(int x) {
    if(LLONG_MAX / x < x-1) return true;
    return x*(x-1) / 2 >= n;
}

void solve() {
    cin >> n;

    int start = 2;
    int end = 1e10;

    while(start != end) {
        int middle = (start + end) / 2;
        if(test(middle)) {
            end = middle;
        } else {
            start = middle+1;
        }
    }

    int ans;

    if(start*(start-1) /2 == n) {
        ans = start;
    } else {
        start--;
        ans = start;
        ans += n - start*(start-1)/2;
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
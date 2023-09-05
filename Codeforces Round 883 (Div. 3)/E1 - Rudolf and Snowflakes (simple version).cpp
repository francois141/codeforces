#include <bits/stdc++.h>
#define int long long
using namespace std;

int sum(int b, int p) {
    int sum = 0;
    int f = 1;
    for(int i = 0; i < p;i++) {
        if(LLONG_MAX - f < sum) return LLONG_MAX;
        sum += f;
        if(LLONG_MAX / b < f) return LLONG_MAX;
        f *= b;
    }

    if(LLONG_MAX - f < sum) return LLONG_MAX;
    sum += f;

    return sum;
}

void solve() {
    int n;
    cin >> n;

    bool ans = false;

    for(int i = 2; i <= 63;i++)  {
        int start = 2;
        int end = 1e9;
        while(start <= end) {
            int middle = (start+end + 1) / 2;
            if(sum(middle, i) == n) {
                ans = true;
                break;
            } else if(sum(middle, i) < n) {
                start = middle+1;
            } else {
                end = middle-1;
            }
        }
    }

    if(ans) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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
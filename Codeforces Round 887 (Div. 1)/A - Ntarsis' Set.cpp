#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;
int n,k;

bool test(int x) {
    int total = x;
    int i = n;

    while(i > 0) {
        if(a[i] <= x) {
            total -= min((total + i - a[i]) / i,k);
        }
        i--;
    }

    return total == 0;
}

void solve() {
    cin >> n >> k;

    a = vector<int> (n+1);
    for(int i = 1; i <= n;i++) cin >> a[i];

    int start = 1;
    int end = 1e12;

    while(start != end) {
        int middle = (start + end) / 2;
        if(test(middle)) {
            start = middle+1;
        } else {
            end = middle;
        }
    }

    cout << start << "\n";
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

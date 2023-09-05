#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,k;
vector<int> a;


bool check(int idx, int coups, int h) {
    if(idx == a.size() || coups < 0) return false;
    if(h <= a[idx]) return true;
    return check(idx+1, coups - (h - a[idx]), h-1);
}

bool test(int x) {
    for(int i = 0; i < n;i++) {
        if(check(i, k, x)) {
            return true;
        }
    }

    return false;
}

void solve() {
    cin >> n >> k;

    a = vector<int>(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int start = 0;
    int end = 2e8;

    while(start != end) {
        int middle = (start + end + 1) / 2;
        if(test(middle)) {
            start = middle;
        } else {
            end = middle-1;
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

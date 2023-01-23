#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;
vector<int> b;
vector<int> c;

int n,m;

bool test(int index) {
    // Case 1
    if(b[index] <= m) return true;
    // Case 2
    if(c[max(index-1,0l)] >= a[index]) {
        return b[max(index-1,0l)] <= m;
    } else {
        return b[max(index-2,0l)] + a[index] <= m;
    }
    // Impossible
    return false;
} 


void solve() {
    cin >> n >> m;

    a = vector<int>(n+1,0);
    for(int i = 1; i <= n;i++) cin >> a[i];

    b = a;
    sort(b.begin(),b.end());
    c = b;

    partial_sum(b.begin(),b.end(),b.begin());

    int start = 0;
    int end = n;

    while(start != end) {
        int middle = (start + end + 1) / 2;

        if(test(middle)) {
            start = middle;
        } else {
            end = middle-1;
        }
    }

    cout << n+1 - start << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> answer;
int n;

void compute(vector<int> &a) {
    auto b = a;

    partial_sum(b.begin(), b.end(), b.begin());

    int leftValue = n-1;
    for(int i = n-2;i >= 0;i--) {

        auto it = upper_bound(b.begin() + leftValue + 1, b.end(), b[i] + a[i]);

        if(it != b.end()) {
            int idx = it - b.begin() - i;
            answer[i] = min(answer[i],idx);
        }

        if(a[i] < a[i+1]) answer[i] = 1;

        if(a[i] != a[leftValue]) leftValue = i;
    }
}

void solve() {
    cin >> n;

    answer = vector<int>(n, INT_MAX);

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    compute(a);

    reverse(a.begin(), a.end());
    reverse(answer.begin(), answer.end());

    compute(a);
    reverse(answer.begin(), answer.end());

    for(auto e: answer) {
        if(e == INT_MAX) {
            cout << -1 << " ";
        } else {
            cout << e << " ";
        }
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

#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> a;

bool test(int size) {
    vector<int> arr(a.size()+1);
    arr.back() = 0;

    for(int i = a.size()-1;i >= 0;i--) {
        arr[i] = max(a[i], arr[i+1] + 1);
    }

    int val = LLONG_MAX;
    int prev = 0;
    int n = a.size();

    for(int i = 0; i < n;i++) {
        int tmp = a[i];

        tmp = max(tmp, prev + n - i);
        tmp = max(tmp, arr[i+1] + i + 1ll);

        val = min(val, tmp);

        prev = max(prev + 1, a[i]);
    }

    return val <= size;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    a = vector<int>(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int start = 0;
    int end = 1e10;

    while(start != end) {
        int middle = (start + end) / 2;
        if(test(middle)) {
            end = middle;
        } else {
            start = middle+1;
        }
    }

    cout << start << "\n";
}

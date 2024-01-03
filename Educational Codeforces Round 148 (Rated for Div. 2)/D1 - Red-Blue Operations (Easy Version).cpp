#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,q;
vector<int> a;
vector<int> k;

bool test(int size, int idx) {
    int coups = k[idx];

    if(coups <= a.size()) {
        for(int i = 0; i < n;i++) {
            if(i < coups &&  a[i] + coups - i < size) return false;
            if(i >= coups && a[i] < size) return false;
        }
        return true;
    }

    int extra = 0;

    for(int i = 0; i < n-1;i++) {
        if(a[i] + coups - i < size) return false;
        extra += (a[i] + coups - i) - size;
    }

    if(coups % 2 == n % 2) {
        if(a.back() + coups - n + 1 < size) return false;
        extra += (a.back() + coups - n + 1) - size;
    } else {
        if(a.back() < size) return false;
        extra += a.back() - size;
    }

    return extra >= (coups - n + 1) / 2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;

    a = vector<int>(n);
    k = vector<int>(q+1);

    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 1; i <= q;i++) cin >> k[i];

    sort(a.begin(), a.end());

    for(int i = 1; i <= q;i++) {
        int start = -1e18;
        int end = 1e18;

        while(start != end) {
            int middle = (start + end + 1) / 2;
            if(test(middle, i)) {
                start = middle;
            } else {
                end = middle-1;
            }
        }

        cout << start << " ";
    }


    cout << "\n";
    return 0;
}

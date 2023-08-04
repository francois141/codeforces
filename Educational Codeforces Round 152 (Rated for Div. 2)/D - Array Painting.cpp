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

    vector<int> b(n, 0);

    int cost = 0;

    for(int i = 0; i < n;i++) {
        if(a[i] == 2) {
            b[i] = 1;

            int j = i;
            while(j > 0 && a[j] != 0) {
                a[j]--;
                j--;
                b[j] = 1;
            }

            while(i < n-1 && a[i] != 0) {
                a[i]--;
                i++;
                b[i] = 1;
            }

            cost++;
        }
    }

    for(int i = 0; i < n;i++) {
        if(b[i] != 0) a[i] = 0;
    }

    for(int i = 0; i < n;i++) {
        if(a[i] == 1) {
            cost++;
            int idx = i;

            while(i+1 < n && a[i+1] == 1) {
                i++;
                b[i] = 1;
            }

            b[idx] = 1;
            if(idx > 0 && b[idx-1] == 0) {
                b[idx-1] = 1;
            } else if(i+1 < n && b[i+1] == 0) {
                b[i+1] = 1;
            }
        }
    }

    cost += count(b.begin(),b.end(),0);

    cout << cost << "\n";

    return 0;
}

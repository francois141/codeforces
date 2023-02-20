#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    int left = 0;
    int right = n-1;

    int max_value = n; 
    int min_value = 1;

    while(right - left >= 2) {
        bool f = false;

        if(a[left] == min_value) {
            f = true;
            left++;
            min_value++;
        } else if(a[right] == min_value) {
            f = true;
            right--;
            min_value++; 
        } else if(a[left] == max_value) {
            f = true;
            left++;
            max_value--;
        } else if(a[right] == max_value) {
            f = true;
            right--;
            max_value--;
        }
 
        if(!f) break;
    }

    if(right - left <= 1) {
        cout << -1 << "\n";
    } else {
        cout << left+1 << " " << right+1 << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}
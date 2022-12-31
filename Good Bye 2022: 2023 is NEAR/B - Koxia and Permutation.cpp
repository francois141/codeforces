#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n,k;
    cin >> n >> k;

    for(int i = 1; i <= n/2;i++) {
        cout << n - i + 1 << " " << i << " "; 
    }

    if(n % 2 == 1){
        cout << n/2 +1;
    } 

    cout << "\n";
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

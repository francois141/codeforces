#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int x;
    cin >> x;

    int freepow = ~x;

    if((freepow | ((x+1) /2)) > freepow) {
        cout << -1 << endl;
    } else {
        int a = x + (x+1)/2;
        int b = (x+1)/2;
        if(a == b) {
            cout << -1 << "\n";
        } else {
            cout << a << " " << b << "\n";
        }
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
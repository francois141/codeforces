#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a,b,c,d;
  cin >> a >> b >> c >> d;

  if(b > d) {
    cout << -1 << "\n";
    return;
  }

  int ans = 0;

  ans += (d - b);
  a += (d-b);
  b += (d-b);

  if(c > a) {
    cout << -1 << "\n";
    return;
  }

  ans += (a - c);

  cout << ans << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--)  
    solve();
}

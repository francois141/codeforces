#include <bits/stdc++.h>
#define int long long
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
  return a * b / gcd(a,b);
}

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);

  for(int i = 0; i < n;i++) {
    cin >> a[i];
    cin >> b[i];
  }

  int ans = 1;

  int lc = b[0];
  int gc = b[0] * a[0];

  for(int i = 1; i < n;i++) {
    if(gcd(gc,b[i]*a[i]) % lcm(lc,b[i])  == 0) {
      lc = lcm(lc,b[i]);
      gc = gcd(gc, b[i]*a[i]);
    } else {
      ans++;
      lc = b[i];
      gc = b[i] * a[i];
    }
  }

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

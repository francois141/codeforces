#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);

  for(int i = 0; i < n;i++)  cin >> a[i];

  int cnt = 0;
  int cnt1 = 0;

  for(auto e: a) {
    if(e == 0) {
      cnt++;
    }
    if(e == 1) {
      cnt1++;
    }
  }

  if(cnt <= (n+1)/2) {
    cout << 0 << "\n";
    return;
  }

  if(cnt + cnt1 == n && cnt1 > 0) {
    cout << 2 << "\n";
  } else {
    cout << 1 << "\n";
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

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int K = 1e9 + 7;

inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}


void solve() {
	int n;
	cin >> n;

	vector<int> fact(n+1,1);

	for(int i = 1; i <= n;i++) {
		fact[i] = mult(i,fact[i-1]);
	}

	fact[0] = 0;

	int ans = 0;
	for(int i = 1; i <= n;i++) {
		int tmp = mult(2,n - i);
		ans = add(ans,mult(fact[n],tmp));
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
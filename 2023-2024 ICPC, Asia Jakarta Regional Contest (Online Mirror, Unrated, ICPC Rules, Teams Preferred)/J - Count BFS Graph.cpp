#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; 

inline int mult(int a,int b) {return ((a)*(b)) % K;}
inline int add(int a,int b) {return ((a)+(b)) % K;}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y & 1) z = mult(z, x);
        x = mult(x, x);
        y >>= 1;
    }
    return z;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n+1);
	for(int i = 1; i <= n;i++) cin >> a[i];

	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	dp[1][0] = 1;

	vector<int> powe(n+1);
	powe[0] = 1;
	for(int i = 1; i <= n;i++) {
		powe[i] = binpow(2, i);
	}

	for(int i = 2; i <= n;i++) {
		
		for(int j = 1; j <= n;j++) {
			dp[i-1][j] = add(dp[i-1][j], dp[i-1][j-1]);
		}

		for(int j = i-1; j >= 1;j--) {
			int until = (a[i] > a[i-1]) ? j : j-1;
			dp[i][j] = add(dp[i][j],mult(dp[i-1][until],powe[i - j - 1]));
		}
	}

	int answer = 0;

	for(auto e: dp.back()) {
		if(e > 0) {
			answer = add(answer, e);
		}
	}

	cout << answer << "\n";
}

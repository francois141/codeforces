#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> tree;

int getDigits(int n)
{
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int getSum(int index )
{
    int sum = 0;
    index = index + 1;
 
    while (index>0)
    {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}
 
void update(int n, int index, int val)
{
    index = index + 1;
    while (index <= n)
    {
		tree[index] += val;
		index += index & (-index);
    }
}
 
void solve() {
	int n,q;
	cin >> n >> q;

	vector<int> a(n);
	for(int i = 0; i < n;i++) cin >> a[i];

	vector<int> applied(n,0);

	tree = vector<int>(n+1);

	while(q--) {
		int t; cin >> t;
		if(t == 1)  {
			int l,r;
			cin >> l >> r;
			l--;
			r--;
			update(n,l,1);
			update(n,r+1,-1);
		} else {
			int x; cin >> x;
			x--;
			while(a[x] > 9 && applied[x] < getSum(x)) {
				applied[x]++;
				a[x] = getDigits(a[x]);
			}
			cout << a[x] << "\n";
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

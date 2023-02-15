#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
int current;
int step;
int aW,aB,bW,bB;

void compute(int &vW, int &vB) {
	if(current >= n) return;
	int currStep = min(n - current,step);
	//cout << currStep << " " << n - current <<  endl;
	int size = currStep / 2;
	int extra = currStep % 2;

	vW += size;
	vB += size;

	if(current % 2 == 0 && extra == 1) {
		vW++;
	} else if(extra == 1){
		vB++;
	}

	current += step;
	step++;
}

void solve() {
	cin >> n;
	current = 0;
	step = 0;

	aW = 0;
	aB = 0;
	bW = 0;
	bB = 0;

	while(current < n) {
		compute(aW,aB);
		compute(aW,aB);
		compute(bW,bB);
		compute(bW,bB);
	}

	cout << aW << " " << aB << " " << bW << " " << bB << "\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--)
		solve();

	return 0;
}
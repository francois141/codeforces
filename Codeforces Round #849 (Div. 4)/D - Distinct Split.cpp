#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> freq(26,0);
	for(auto c : s) freq[c-'a']++;

	int current = count_if(freq.begin(),freq.end(),[](int i) { return i > 0;});
	int best = current;	

	set<int> f2;

	for(auto c : s) {
		if(f2.find(c-'a') == f2.end()) {
			current++;
			f2.insert(c-'a');
		}

		freq[c-'a']--;
		if(freq[c-'a'] == 0) current--;

		best = max(current,best);
	}

	cout << best << "\n";
}	

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	while(t--)	
		solve();
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

map<char,int> mp;
char pos[3] = {'w','i','n'};

struct ans {
	int idx1;
	int idx2;
	char c1;
	char c2;
};

void solve() {
	int m;
	cin >> m;

	set<int> st[3][3];

	for(int i = 0; i < m;i++) {
		string s;
		cin >> s;

		vector<int> cnt(3,0);
		for(auto x: s)
			cnt[mp[x]]++;

		for(int j = 0 ; j < 3;j++) {
			for(int k = 0; k < 3;k++) {
				if(cnt[j] >= 2 && !cnt[k])
					st[j][k].insert(i);
			}
		}
	}

	vector<ans> answer;

	for(int i = 0; i < m;i++) {
		for(int j = 0; j < 3;j++) {
			for(int k = 0; k < 3;k++) {
				if(st[j][k].count(i)) {
					if(st[k][j].size()) {
						int val = *st[k][j].begin();
						st[j][k].erase(i);
						st[k][j].erase(val);
						answer.push_back(ans{i,val,pos[j],pos[k]});
					} else {
						int k1 = 3-k-j;
						int val = *st[k][k1].begin();
						answer.push_back(ans{i,val,pos[j],pos[k]});
						st[j][k].erase(i);
						st[k][k1].erase(val);
						st[j][k1].insert(val);
					}
				}
			}
		}
	}

	cout << answer.size() << "\n";
	for(auto a : answer) {
		cout << a.idx1+1 << " " << a.c1 << " " << a.idx2+1 << " " << a.c2 << "\n";
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;

	mp['w']=0;
	mp['i']=1;
	mp['n']=2;

	while(t--)
		solve();

	return 0;
}

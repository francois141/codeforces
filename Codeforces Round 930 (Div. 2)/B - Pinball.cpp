#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    s = " " + s;

    // Precompute
    vector<int> values1,values2;

    values1.push_back(0);
    values2.push_back(0);

    for(int i = 1; i <= n;i++) {
        if(s[i] == '>') {
            values1.push_back(i);
        } else {
            values2.push_back(n-i+1);
        }
    }

    values1.push_back(0);
    values2.push_back(0);

    for(int i = values1.size()-1; i >= 0;i--) values1[i] += values1[i+1];
    for(int i = 1; i < values2.size();i++) values2[i] += values2[i-1];

    int idx1 = 0;
    int idx2 = 1;

    for(int i = 1; i <= n;i++) {
        // Update ds
        if(s[i] == '>') idx1++;

        // Base value
        int size = min(idx1, (int)values2.size()-idx2-1);
        int answer = (n+1)*2*size;

        // Compute
        answer -= 2*(values1[idx1-size+1] - values1[idx1+1]);
        answer -= 2*(values2[idx2+size-1] - values2[idx2-1]);

        if(s[i] == '>' && idx1 > (int)values2.size()-idx2-1) {
            answer += (n+1);
            answer -= 2*(values1[idx1-size]-values1[idx1-size+1]);
        }
        if(s[i] == '<' && (int)values2.size()-idx2-1 > idx1) {
            answer += (n+1);
            answer -= 2*(values2[idx2+size]-values2[idx2+size-1]);
        }

        // Correction
        if(s[i] == '>') answer += i;
        if(s[i] == '<') answer += n - i + 1;

        cout << answer << " ";

        // Update ds
        if(s[i] == '<') idx2++;
    }

    cout << "\n";
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

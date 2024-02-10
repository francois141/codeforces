#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = count(s.begin(), s.end(), '1');

    vector<unordered_map<int,int>> dp(1,unordered_map<int,int>());
    dp[0][0] = 0;

    for(int i = 0; i < s.size();i++) {
        vector<unordered_map<int,int>> dp2(max(i, cnt0) + 1);
        for(int curr0 = 0; curr0 < dp.size();curr0++) {
            int curr1 = i - curr0;
            for(auto p: dp[curr0]) {
                // Add 0
                if(curr0 < cnt0) {
                    int dis = cnt1 - curr1;

                    int displacement = p.first + dis;
                    int cost = p.second + ((s[i] == '1') ? 1 : 0);

                    if(dp2[curr0+1].find(displacement) == dp2[curr0+1].end()) dp2[curr0+1][displacement] = cost;
                    else dp2[curr0+1][displacement] = min(dp2[curr0+1][displacement], cost);
                }
                // Add 1
                if(curr1 < cnt1) {
                    int dis = -(cnt0 - curr0);

                    int displacement = p.first + dis;
                    int cost = p.second + ((s[i] == '0') ? 1 : 0);

                    if(dp2[curr0].find(displacement) == dp2[curr0].end()) dp2[curr0][displacement] = cost;
                    else dp2[curr0][displacement] = min(dp2[curr0][displacement], cost);
                }
            }
        }

        dp = dp2;
    }

    cout << dp[cnt0][0]/2 << "\n";

    return 0;
}

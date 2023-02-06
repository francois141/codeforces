#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pair<int,int>> freq(26,make_pair(0,0));
    for(int i = 0; i < 26;i++) freq[i].second = i;
    for(auto c : s) freq[c - 'a'].first++;
    sort(freq.begin(),freq.end(),greater<pair<int,int>>());

    int score = INT_MAX;
    int bestSize = INT_MAX;
    int bestFrequence = INT_MAX;
    for(int i = 1; i <= 26;i++) {
        if(n % i != 0) continue;
        int h = n / i;
        int price = 0;
        for(int j = 0; j < i;j++) 
            price += max(h - freq[j].first,0ll);
        
        if(price < score) {
            score = price;
            bestSize = i;
            bestFrequence = n/i;
        }
    }

    cout << score << "\n";

    map<int,int> mp;
    for(int i = 0; i < bestSize;i++) {
        mp[freq[i].second] = bestFrequence;
    }

    string ans = "";
    ans.append(n,'-');

    for(int i = 0; i < n;i++) {
        if(mp[s[i] - 'a'] > 0) {
            ans[i] = s[i];
            mp[s[i]-'a']--;
        }  
    }

    for(int i = 0; i < n;i++) {
        if(ans[i] == '-') {
            while(mp.begin()->second == 0) {
                mp.erase(mp.begin());
            }
            ans[i] = 'a' + mp.begin()->first;
            mp.begin()->second--;
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

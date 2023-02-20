#include <bits/stdc++.h>
#define int long long
using namespace std;

int c (int value) {
    if(value <= 0) return 0;
    return (value+1)*value/2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<pair<int,int>> p = vector<pair<int,int>>(n);
    vector<pair<int,int>> q = vector<pair<int,int>>(n);

    for(int i = 0; i < n;i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    for(int i = 0; i < n;i++) {
        cin >> q[i].first;
        q[i].second = i;
    }

    sort(p.begin(),p.end());
    sort(q.begin(),q.end());

    int ans = 1;

    int pos1 = p[0].second;
    int pos2 = q[0].second;

    auto mima = minmax(pos1,pos2);

    ans += c(mima.first);
    ans += c(mima.second - mima.first - 1);
    ans += c(n - mima.second -1);

    int left_range = INT_MAX;
    int right_range = INT_MIN;

    for(int i = 1; i < n;i++) {
        left_range = min({left_range,p[i-1].second,q[i-1].second});
        right_range = max({right_range,p[i-1].second,q[i-1].second});
        
        pos1 = p[i].second;
        pos2 = q[i].second;

        if(left_range < pos1 && pos1 < right_range) continue;
        if(left_range < pos2 && pos2 < right_range) continue;

        auto mima = minmax(pos1,pos2);
        int v1,v2;

        if(mima.second < left_range) {
            v1 = left_range - mima.second; 
            v2 = n - right_range;
        } else if(mima.first > right_range) {  
            v1 = mima.first - right_range;
            v2 = left_range + 1;
        } else {
            v1 = mima.first - left_range;
            v2 = right_range - mima.second;
        }

        ans += v1*v2;
    }

    cout << ans << "\n";
}
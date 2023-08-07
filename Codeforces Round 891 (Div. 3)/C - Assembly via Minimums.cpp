#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int size = n*(n-1)/2;

        vector<int> a(size);
        for(int i = 0; i < size;i++) cin >> a[i];

        sort(a.begin(), a.end());

        int value = 1;

        vector<int> ans = {(int)1e9};

        while(a.size() > 0) {
            int tmp = value++;
            ans.push_back(a.back());
            while(tmp--) {
                a.pop_back();
            }
        }

        for(auto e: ans) cout << e << " ";
        cout << "\n";
    }

    return 0;
}
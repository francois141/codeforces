#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans;
vector<int> a;

void compute(int x) {
    int score = 0;

    for(auto e : a) {
        int f = sqrt(e+x);
        if(f*f == e+x)
            score++; 
    }

    ans = max(ans,score);
}

void solve() {
    int n;
    cin >> n; 

    a = vector<int>(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    ans = 1;
    for(int i = 0; i < n;i++) {
        for(int j = i+1; j < n;j++) {
            int value = a[j] - a[i];
            for(int div = 1; div*div <= value;div++) {
                if(value % div == 0) {
                    int q = value/div + div;
                    if(q % 2 == 0) {
                        q /= 2;
                        int x = q*q - a[j]; 
                        if(q*q >= a[j]) {
                            compute(x);
                        }                
                    }
                }
            }
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

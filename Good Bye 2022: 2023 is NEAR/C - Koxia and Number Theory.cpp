#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> primes;

void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) primes.push_back(p);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> a = vector<int>(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    sort(a.begin(), a.end());
    auto it = std::unique(a.begin(), a.end());
    bool unique = (it == a.end());

    if(!unique) {
        cout << "no" << "\n";
        return;
    }

    for(auto p:primes) {
        vector<int> eq = vector<int>(p);
        for(int i = 0; i < n;i++) {
            eq[a[i] % eq.size()]++;
        }
        if(*min_element(eq.begin(),eq.end()) > 1) {
            cout << "no" << "\n";
            return;
        }
    }

    cout << "yes" << "\n";
}
 
signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    primes = vector<int>(0);
    SieveOfEratosthenes(1e3);

    while(t--) {
        solve();
    }
}

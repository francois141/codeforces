#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
vector<int> lp(N+1);
vector<int> pr;

void linearSieve()  {
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
}

void trial_division1(map<int,int> &divMap,long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            divMap[d]++;
            n /= d;
        }
    }

    if(n > 1) divMap[n]++;
}

map<int,int> mp;
int divisors;
int init;
int n,q;



void reset() {
    n = init;
    mp.clear();

    int tmp = init;
    while(tmp > 1) {
        mp[lp[tmp]]++;
        tmp /= lp[tmp];
    }

    divisors = 1;
    for(auto e: mp)  {
        divisors *= (e.second + 1);
    }
}

void solve() {
    cin >> n >> q;

    init = n;
    reset();

    while(q--) {
        int k;
        cin >> k;

        if(k == 1) {
            int x;
            cin >> x;
            while(x > 1) {
                divisors /= (mp[lp[x]] + 1);
                mp[lp[x]]++;
                divisors *= (mp[lp[x]] + 1);
                x /= lp[x];
            }

            map<int,int> divMap;
            trial_division1(divMap, divisors);

            bool ok = true;

            for(auto e : divMap) {
                ok &= divMap[e.first] <= mp[e.first];
            }

            cout << (ok ? "YES" : "NO") << "\n";
        } else {
            reset();
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    linearSieve();

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

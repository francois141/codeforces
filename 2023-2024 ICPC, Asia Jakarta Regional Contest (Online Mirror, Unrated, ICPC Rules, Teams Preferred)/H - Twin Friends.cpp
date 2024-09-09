#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353; // or 1e9 + 7;

inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}

vector<int> factorial;

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y & 1) z = mult(z, x);
        x = mult(x, x);
        y >>= 1;
    }
    return z;
}

int inverse(int a) {
    return binpow(a,K-2);
}

int divide(int a, int b) {
    return mult(a,inverse(b));
}

int binomial_coefficient(int n, int k) {
    return divide(factorial[n], mult(factorial[k],factorial[n - k]));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    factorial = vector<int>(1e6+1,1);
    for(int i = 1; i <= 1e6;i++) {
        factorial[i] = mult(i, factorial[i-1]);
    }

    int n,m;
    cin >> n >> m;

    string a,b;
    cin >> a >> b;

    vector<int> freqA(27), freqB(27);
    for(auto e: a) freqA[e - 'A']++;
    for(auto e: b) freqB[e - 'A']++;
    freqA[26] = freqB[26] = 0;

    vector<vector<int>> dp(27);
    dp[0] = vector<int>(1);
    dp[26].push_back(factorial[a.size()]);
    for(int i = 0; i < 26;i++) {
        dp[26][0] = divide(dp[26][0], factorial[freqA[i]]);
        dp[i] = vector<int>(freqA[i]+1);
    }

    // dp[i][j] = j taken during last step
    for(int idx = 25; idx >= 0;idx--) {
        for(int i = 0; i <= min(freqB[idx], freqA[idx]);i++) {
            int need = freqA[idx] - i;
            int j = min(freqB[idx+1]-need, (int)dp[idx+1].size()-1);
            if(j >= 0) {
                int value = mult(dp[idx+1][j], binomial_coefficient(freqA[idx], need));
                dp[idx][i] = add(dp[idx][i], value);

            }
        }

        for(int i = 1; i < dp[idx].size();i++)  {
            dp[idx][i] = add(dp[idx][i], dp[idx][i-1]);
        }
    }

    cout << dp[0].back() << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;
#define int long long

const int K = 1e9 + 7;

int mult(int a, int b) {
    return (a * b) % K;
}

int add(int a, int b) {
    return (a + b) % K;
}

vector<vector<int>> matmult(vector<vector<int>> &m1, vector<vector<int>> &m2) {
    vector<vector<int>> c(m1.size(), vector<int>(m2.size(),0));
    for (int i = 0; i < m1.size();i++){
        for (int j = 0; j < m2[0].size();j++){
            for(int k = 0; k < m2.size();k++) {
                c[i][j] = add(c[i][j], mult(m1[i][k],m2[k][j]));
            }
        }
    }
 
    return c;
}
 
vector<int> vmult(vector<vector<int>> &matrix, vector<int> &vec) {
    vector<int> sol(matrix.size());
 
    for (int i = 0; i < matrix.size();i++){
        for (int j = 0; j < vec.size();j++){
            sol[i] = add(sol[i], mult(matrix[i][j], vec[j]));
        }
    }
 
    return sol;
}
 
vector<vector<int>> binpow(vector<vector<int>> &matrix, int y)
{
    vector<vector<int>> sol(matrix.size(), vector<int>(matrix[0].size(), 0));
    for(int i = 0; i < matrix.size();i++) sol[i][i] = 1;
 
    while(y)
    {
        if(y & 1) sol = matmult(sol, matrix);
        matrix = matmult(matrix, matrix);
        y >>= 1ll;
    }
 
    return sol;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> m >> n;

    vector<int> s(m);
    vector<int> l(m);

    for(int i = 0; i < m;i++) cin >> s[i];
    for(int i = 0; i < m;i++) cin >> l[i];

    int sumS = accumulate(s.begin(), s.end(), 0ll);
    int sumL = accumulate(l.begin(), l.end(), 0ll);
    
    int ss = 0;
    int sl = 0;
    int ll = 0;
    for(int i = 0; i < m;i++) {
        ss = add(ss, s[i] * s[i]);
        sl = add(sl, s[i] * l[i]);
        ll = add(ll, l[i] * l[i]); 
    }
    int ls = sl;

    vector<int> dp(2);

    // Start
    dp[0] = s[0];
    dp[1] = l[0];

    vector<vector<int>> matrix(2,vector<int>(2));

    matrix[0][0] = add(ss, ls);
    matrix[0][1] = ss;
    matrix[1][0] = add(sl, ll);
    matrix[1][1] = sl;

    matrix = binpow(matrix, n-1);
    dp = vmult(matrix, dp);
    
    int ans = add(mult(add(dp[0], dp[1]), sumS), mult(dp[0],sumL));
    
    cout << ans << "\n";

    return 0;
}

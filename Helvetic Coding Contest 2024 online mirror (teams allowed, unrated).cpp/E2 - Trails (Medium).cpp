#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 1e9+7;

inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}

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
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m,n;
    cin >> m >> n;

    vector<int> s(m),l(m);
    for(int i = 0; i < m;i++) cin >> s[i];
    for(int i = 0; i < m;i++) cin >> l[i];

    vector<vector<int>> transition(m, vector<int>(m,0));
    for(int i = 0; i < m;i++) {
        for(int j = 0; j < m;j++) {
            transition[i][j] = s[i] * (s[j] + l[j]) + l[i] * s[j];
        }
    }

    auto final = binpow(transition, n);

    vector<int> init(m, 0);
    init[0] = 1;
    auto vec = vmult(final, init);

    int ans = 0;
    for(auto e: vec) ans = add(ans, e);

    cout << ans << "\n";

    return 0;
}

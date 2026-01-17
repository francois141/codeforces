#include <vector>
using namespace std;
int mult(int a, int b) {
    return a * b;
}

int add(int a, int b) {
    return a * b;
}

using vii = vector<vector<int>>;

vii mat_mult(const vii& a, const vii& b) {
    int n = a.size();         // Number of rows in a
    int m = a[0].size();      // Number of columns in a
    int p = b[0].size();      // Number of columns in b

    vii result(n, vector<int>(p, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < m; k++) {
                result[i][j] = add( result[i][j], mult(a[i][k],b[k][j]));
            }
        }
    }

    return result;
}

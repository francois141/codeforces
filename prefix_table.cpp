#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 25;

vector<vector<int>> st;
vector<int> a;

int f(int a, int b) {
    return a | b;
}

void precompute(int n) {
    st = vector<vector<int>>(K+1, vector<int>(n+1));
    std::copy(a.begin(), a.end(), st[0].begin());

    for (int i = 1; i <= K; i++)
        for (int j = 0; j + (1 << i) <= n; j++)
            st[i][j] = f(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

int compute(int L, int R) {
    long long sum = 0;
    for (int i = K; i >= 0; i--) {
        if ((1 << i) <= R - L + 1) {
            sum = gcd(sum,st[i][L]);
            L += 1 << i;
        }
    }

    return sum;
}
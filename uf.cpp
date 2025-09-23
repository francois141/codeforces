#ifdef ONLINE_JUDGE
#include <bits/stdc++.h>
#endif
#include <iostream>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>
#include <utility>
#define int long long
using namespace std;

vector<int> parent;


int find(int a) {
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void unite(int a, int b, int index) {
    a = find(a);
    b = find(b);

    if(a == b) return;

    // Bind a to b
    parent[a] = b;
}

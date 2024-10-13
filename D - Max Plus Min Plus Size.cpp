#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> parent;

int find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if(a == b) return;

    parent[b] = a;
}

bool test(int value) {
    return value == 1 || (value % 2 == 0);
}

void solve() {
    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    vector<int> sizes(n, 0);
    vector<pair<int,int>> positions(n);

    for(int i = 0; i < n;i++) cin >> a[i].first;
    for(int i = 0; i < n;i++) a[i].second = i;

    sort(a.rbegin(), a.rend());

    parent = vector<int>(n);
    iota(parent.begin(), parent.end(), 0ll);

    int ans = 0;
    int nb = 0;
    int good = 0;
    pair<int,int> pos;

    for(auto p: a) {
        int currLen = 1;
        pair<int,int> currPos = {0,0};
        if(p.first == a[0].first) currPos.first++;

        bool isPair = true;
        if(p.second > 0 && sizes[find(p.second-1)]) {
            // Update nombre
            nb -= (sizes[find(p.second-1)] + 1) / 2;
            currLen += sizes[find(p.second-1)];
            // Update positions
            isPair = !(sizes[find(p.second-1)] & 0x1);
            // Get and delete
            auto pos2 = positions[find(p.second-1)];
            pos.first -= pos2.first;
            pos.second -= pos2.second;
            // Set current
            if(!isPair) swap(currPos.first, currPos.second);
            currPos.first += pos2.first;
            currPos.second += pos2.second;

            if(test(sizes[find(p.second-1)]) && (pos2.first != 0 || pos2.second != 0)) good--;

            unite(p.second-1, p.second);
        }

        if(p.second < n-1 && sizes[find(p.second+1)]) {
            // Update nombre
            nb -= (sizes[find(p.second+1)] + 1) / 2;
            currLen += sizes[find(p.second+1)];
            // Get and delete
            auto pos2 = positions[find(p.second+1)];
            pos.first -= pos2.first;
            pos.second -= pos2.second;
            // Set current
            if(isPair) swap(pos2.first, pos2.second);
            currPos.first += pos2.first;
            currPos.second += pos2.second;

            if(test(sizes[find(p.second+1)]) && (pos2.first != 0 || pos2.second != 0)) good--;

            unite(p.second+1, p.second);
        }

        nb += (currLen + 1) / 2;
        sizes[find(p.second)] = currLen;
        // Update structure
        pos.first += currPos.first;
        pos.second += currPos.second;
        positions[find(p.second)] = currPos;

        if(test(sizes[find(p.second)]) && (currPos.first != 0 || currPos.second != 0)) good++;

        ans = max(ans, nb + p.first + a[0].first + (pos.first == 0 && good == 0 ? -1 : 0));
    }

    cout << ans << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }


    return 0;
}

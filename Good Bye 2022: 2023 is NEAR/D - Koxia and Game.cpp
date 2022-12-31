#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353;

vector<vector<int>> graph;
vector<int> a;
vector<int> b;
vector<bool> taken;

bool dfs(int idx, int p=-1) {
    taken[idx] = true;
    for(auto next : graph[idx]) {
        if(next == p || next == idx) continue;
        
        if(taken[next]) return false;
        if(!dfs(next,idx))return false;
    }
    return true;
}

vector<int> chef;

int find(int a){
    if(a == chef[a]){
        return a;
    }
    chef[a] = find(chef[a]);
    return chef[a];
}

void unite(int a, int b){
    a = find(a); 
    b = find(b);
    chef[a] = b;
}



void solve() {
    int n;
    cin >> n;

    a = vector<int>(n);
    b = vector<int>(n);

    for(int i = 0; i < n;i++) cin >> a[i];
    for(int i = 0; i < n;i++) cin >> b[i];

    graph = vector<vector<int>>(n+1,vector<int>(0));

    for(int i = 0; i < n;i++) {
        graph[a[i]].push_back(b[i]);
        graph[b[i]].push_back(a[i]);
    }

    set<int> single;

    for(int i = 0; i < n;i++) {
        if(a[i] == b[i]) {
            if(single.find(a[i]) != single.end()) {
                cout << 0 << "\n";
                return;
            }
            single.insert(a[i]);
        }
    }

    int solution = 1;
    taken = vector<bool>(n,false);

    for(auto start : single) {
        if(!dfs(start)) {
            cout << 0 << "\n";
            return;
        }
        solution = (solution * (n)) % K;
    }

    map<int,int> translate;

    int current = 0;
    chef = vector<int>(0);

    for(int i = 1; i <= n;i++) {
        if(!taken[i]) {
            translate[i] = current;
            chef.push_back(current++);
        }
    }

    for(int i = 0; i < n;i++) {
        if(!taken[a[i]])
            unite(translate[a[i]],translate[b[i]]);
    }

    map<int,int> sizes;

    for(int i = 0; i < chef.size();i++) {
        sizes[find(i)]++;
    }

    for(int i = 0; i < n;i++) {
        if(!taken[a[i]])
            sizes[find(translate[a[i]])]--;
    }

    for(auto p: sizes) {
        if(p.second != 0) {
            cout << 0 << "\n";
            return;
        }
    }

    set<int> uniques = set<int>(chef.begin(),chef.end());
    for(int i = 0; i < uniques.size();i++) {
        solution = (2*solution) % K;
    }

    cout << solution << "\n";
}

signed main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct trie {
    int size;
    vector<trie*> childs;
};

trie* newNode() {
    trie* child = new trie;
    child->size = 0;
    child->childs = vector<trie*>(26, nullptr);
    return child;
}

void insert(string &s, int idx, trie* current) {
    if(idx >= s.size()) {
        current->size++;
        return;
    }

    current->size++;
    int nextIdx = s[idx] - 'a';
    if(current->childs[nextIdx] == nullptr) current->childs[nextIdx] = newNode();
    insert(s, idx+1, current->childs[nextIdx]);
}

int find(string &s, int idx, trie* current) {
    if (current == nullptr) return 0;
    if (idx == s.size()) {
        return current->size * idx;
    }

    int nextIdx = s[idx] - 'a';

    int sep = current->size;
    if(current->childs[nextIdx] != nullptr) sep -= current->childs[nextIdx]->size;

    return sep * (idx) + find(s, idx+1, current->childs[nextIdx]);
}

trie *root;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    root = newNode();

    vector<string> values(n);
    for(int i = 0; i < n;i++) cin >> values[i];

    int ans = 0;
    for(auto e: values) {
        ans += 2*n*e.size();
        insert(e, 0, root);
    }

    for(auto e: values) {
        reverse(e.begin(), e.end());
        ans -= 2*find(e, 0, root);
    }

    cout << ans << "\n";
}

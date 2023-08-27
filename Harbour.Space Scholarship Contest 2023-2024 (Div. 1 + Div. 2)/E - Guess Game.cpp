#include <bits/stdc++.h>
#define int long long
using namespace std;

const int K = 998244353;

inline int mult(int a,int b) {return ((a%K)*(b%K)) % K;}
inline int add(int a,int b) {return ((a%K)+(b%K)) % K;}

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

struct trie {
    struct trie *child[2];
    int nb;
    bool isFinal;
};

trie* createNode() {
    trie* node = (trie*)malloc(sizeof(trie));
    node->child[0] = node->child[1] = NULL;
    node->nb = 0;
    node->isFinal = false;
    return node;
}

void insert(trie *root, int value, int pos = 30) {
    root->nb++;

    if(pos < 0) {
        root->isFinal = true;
        return;
    }

    int bit = (value >> pos) & 0x1;
    if(root->child[bit] == NULL) {
        root->child[bit] = createNode();
    }

    insert(root->child[bit], value, pos-1);
}

int dfs(trie *root, int nbOnes = 0) {
    int val = 0;

    if(root->isFinal) {
        int tmp = mult(mult(root->nb, root->nb), add(1, nbOnes));
        return add(val, tmp);
    }

    if (root->child[0] != NULL && root->child[1] != NULL) {
        int tmp = mult(mult(root->child[0]->nb, root->child[1]->nb), add(3, mult(2, nbOnes)));
        val = add(val, tmp);
    }

    if(root->child[0] != NULL) {
        val = add(val, dfs(root->child[0], nbOnes));
    }

    if(root->child[1] != NULL) {
        val = add(val, dfs(root->child[1], nbOnes+1));
    }

    return val;
}

void solve() {
    int n;
    cin >> n;

    trie *root = createNode();
    for(int i = 0; i < n;i++) {
        int x;
        cin >> x;
        insert(root, x);
    }

    int total = dfs(root);
    int div = mult(n,n);

    cout << divide(total, div) << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}

vector<int> tree;
vector<int> lazy;

int n,m;

void build() {
    tree = vector<int>(4*m);
    lazy = vector<int>(4*m);
}

void push(int v) {
    tree[2*v] += lazy[v];
    tree[2*v+1] += lazy[v];
    lazy[2*v] += lazy[v];
    lazy[2*v+1] += lazy[v];
    lazy[v] = 0;
}

void update(int idx, int tl, int tr, int l, int r, int modif) {
    if(l > r) return;

    if(l == tl && r == tr) {
        tree[idx] += modif;
        lazy[idx] += modif;
    } else {
        push(idx);
        int tm = (tl + tr) / 2;
        update(2*idx, tl, tm, l, min(r, tm), modif);
        update(2*idx+1, tm+1, tr, max(l, tm+1), r, modif);
        tree[idx] = min(tree[2*idx], tree[2*idx+1]);
    }
}

int query(int idx, int tl, int tr, int l, int r) {
    if(l > r) return INT_MAX;
    if(l == tl && r == tr) return tree[idx];

    push(idx);
    int tm = (tl + tr) / 2;
    
    int q1 = query(2*idx, tl, tm, l, min(r, tm));
    int q2 = query(2*idx+1, tm+1, tr, max(l, tm+1), r);

    return min(q1, q2);
}

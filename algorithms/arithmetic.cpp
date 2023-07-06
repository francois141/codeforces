#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef vector<int> lnum;

void output(lnum a) {
    cout << ("%d", a.empty() ? 0 : a.back());
    for (int i=(int)a.size()-2; i>=0; --i)
        cout << a[i];
}

lnum add(lnum a, lnum b) {
    int carry = 0;
    for(size_t i = 0; i < max(a.size(),b.size()) || carry; i++) {
        if(i == a.size()) {
            a.push_back(0);
        }

        if(carry) a[i]++;
        carry = 0;

        if(i < b.size()) a[i] += b[i];
        if(a[i] > 9) {
            carry++;
            a[i] -= 10; 
        }
    }

    return a;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    {
        lnum a;
        lnum b;
        a.push_back(6);
        b.push_back(5);
        lnum c = add(a,b);
        assert(c[0] == 1 && c[1] == 1); 
    }

}
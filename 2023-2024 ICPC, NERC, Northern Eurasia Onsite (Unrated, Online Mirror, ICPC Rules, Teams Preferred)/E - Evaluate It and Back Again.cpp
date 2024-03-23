#include <bits/stdc++.h>
#define int long long
using namespace std;

int lead(int val) {
    int tmp = 0;
    while(val != 0) {
        tmp = val % 10;
        val /= 10;
    }
    return tmp;
}

string ans;

void fixDiff(int diff)  {
    if(diff == 0) return;
    if (diff == 9) {
        fixDiff(4);
        fixDiff(5);
    } else if(diff < 10) {
        ans += to_string(diff+1) + "-" + to_string(1) + "+";
    } else {
        int rest = lead(diff);
        ans += to_string(diff + rest) + "-" + to_string(rest) + "+";
    }
}

void fixDiffInv(int diff)  {
    if(diff == 0) return;
    if (diff == 9) {
        fixDiffInv(4);
        fixDiffInv(5);
    } else if(diff < 10) {
        ans += to_string(1) + "-" + to_string(diff+1) + "+";
    } else {
        int rest = lead(diff);
        ans += to_string(rest) + "-" + to_string(diff + rest) + "+";
    }
}

void ajust(int diff) {
    if(diff == 0) return;
    if(diff < 10) {
        ans += to_string(diff) + "+" + to_string(0) + "+";
    } else if(lead(diff) == 1) {
        ans += to_string(diff-1) + "+" + to_string(1) + "+";
    } else {
        int l = lead(diff)-1;
        ans += to_string(diff - (10 - l)) + "+" + to_string(10 - l) + "+";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int p,q;
    cin >> p >> q;

    ans = "0+";

    if(abs(p-q) & 0x1) {
        ans += "12-0+";
        p -= 12;
        q += 21;
    }

    int diff = (p - q) / 2;
    int current = 0;

    int tmp = 10;
    while(diff > 0) {
        int rest = diff % tmp;
        fixDiff(rest);
        diff -= rest;
        current += rest;
        tmp *= 10;
    }

    diff = -diff;

    tmp = 10;
    while(diff > 0) {
        int rest = diff % tmp;
        fixDiffInv(rest);
        diff -= rest;
        current -= rest;
        tmp *= 10;
    }

    diff = p - current;

    if(diff < 0) {
        int v = 1;
        while(v + diff < 0) {
            v *= 10;
        }

        ans += "0-" + to_string(v+1) + "-" + to_string(v+1) + "+";
        ans += to_string(v+1) + "-" + to_string(v+1) + "-0+";

        diff += 2*(v+1);
    }

    tmp = 10;
    while(diff > 0) {
        int rest = diff % tmp;
        ajust(rest);
        diff -= rest;
        tmp *= 10;
    }

    if(ans.back() == '+') {
        ans.pop_back();
    }

    assert(ans.size() <= 1000);

    cout << ans << "\n";

    return 0;
}

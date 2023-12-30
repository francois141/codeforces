#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> cnt(int nb) {
    nb *= nb;
    vector<int> out(10, 0);
    while(nb > 0) {
        out[nb % 10]++;
        nb /= 10;
    }
    return out;
}

string generate(int n, vector<int> val) {
    string ans = "";
    for(int i = 0; i < n;i++) ans += '0';

    for(auto e1: val) {
        for(auto e2: val) {
            ans[e1 + e2]++;
            if(ans[e1 + e2] == '3') return "";
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

void brute(int n) {
    int count = 0;
    for(int i = 0; i < n / 2;i++) {
        for(int j = i + 1; j < n / 2;j++) {
            string s = generate(n, {n/2, i,j});
            if(s == "") continue;
            cout << s << "\n";
            count++;
            if(count == n) return;
        }
    }
}

void solve() {
    int n;
    cin >> n;

    if(n == 1) {
        cout << "1" << "\n";
        return;
    } else if(n == 3) {
        cout << "169" << "\n";
        cout << "196" << "\n";
        cout << "961" << "\n";
        return;
    } else if(n == 5) {
        cout << "16384" << "\n";
        cout << "31684" << "\n";
        cout << "36481" << "\n";
        cout << "38416" << "\n";
        cout << "43681" << "\n";
        return;
    } else if(n == 7) {
        vector<int> v = {1638400,3168400,3648100,3806401,3841600,4036081,4368100};
        for(auto e : v) cout << e << "\n";
    }  else if(n == 9) {
        vector<int> v = {107184609,116704809,118004769,149817600,161798400,167184900,168974001,174160809,187964100};
        for(auto e : v) cout << e << "\n";
    }  else if(n == 11) {
        vector<int> v = {10002400144,10004200441,10020410404,10024014400,10040240401,10042044100,10201404004,10241440000,10404204001,10424410000,12100440004};
        for(auto e : v) cout << e << "\n";
    }   else if(n == 13) {
        vector<int> v = {1000024000144,1000042000441,1000204010404,1000240014400,1000402040401,1000420044100,1002041040400,1002401440000,1004024040100,1004204410000,1020104040004,1020140400400,1024144000000};
        for(auto e : v) cout << e << "\n";
    }  else {
        brute(n);
    }
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

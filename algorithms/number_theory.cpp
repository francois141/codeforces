
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

vector<int> getPrimes(int x) {
    vector<int> ans(0);
    for(int i = 2; i*i <= x;i++) {
        if(x % i == 0) {
            ans.push_back(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x > 1) ans.push_back(x); 

    return ans;
}
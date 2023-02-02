const int K = 998244353; // or 1e9 + 7

inline int mult(int a,int b) {return (a*b) % K;}
inline int add(int a,int b) {return (a+b) % K;}

vector<int> factorial;

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

int binomial_coefficient(int n, int k) {
    return divide(factorial[n], mult(factorial[k],factorial[n - k]));
}

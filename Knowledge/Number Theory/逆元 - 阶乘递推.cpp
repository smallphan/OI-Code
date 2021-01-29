#include <cstdio>

using namespace std;

typedef long long li;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

li n, fac[maxn], invfac[maxn];

inline int inv(int);
void exgcd(int, int, int&, int&);

int main() {
    scanf("%lld", &n);
    fac[0] = 1;
    for (li i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    invfac[n] = inv(fac[n]);
    for (li i = n - 1; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % mod;
    }
    for (int i = 0; i <= n; i++) {
        printf("%lld\n", invfac[i]);
    }
    return 0;
}

inline int inv(int now) {
    int x, y;
    exgcd(now, mod, x, y);
    return (x % mod + mod) % mod;
}

void exgcd(int a, int b, int& x, int& y) {
    if (!b) x = 1, y = 0;
    else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}
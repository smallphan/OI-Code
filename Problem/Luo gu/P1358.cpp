#include <bits/stdc++.h>

inline long long read() {
    char str = getchar();
    long long ans = 0, tag = 1;
    while (str < '0' || str > '9') {
        tag = str == '-' ? -1 : 1;
        str = getchar();
    }
    while (str >= '0' && str <= '9') {
        ans = ans * 10 + str - '0';
        str = getchar();
    }
    return ans * tag;
}

const int mod = 1e4 + 7;
const int maxn = 1e4 + 5;

int n, m, now, ans = 1;
int fac[maxn], invfac[maxn];

inline void init();
inline int inv(int);
inline int C(int, int);
void exgcd(int, int, int&, int&);

int main() {
    n = read(), m = read(), init();
    for (int i = 1; i <= m; i++) {
        now = read();
        ans = (1ll * ans * C(n, now)) % mod;
        n -= now;
    }
    return printf("%d\n", ans), 0;
}

inline void init() {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
    invfac[n] = inv(fac[n]);
    for (int i = n - 1; i >= 0; i--) invfac[i] = 1ll * invfac[i + 1] * (i + 1) % mod;
}

inline int inv(int now) {
    int x, y;
    exgcd(now, mod, x, y);
    return (x % mod + mod) % mod;
}

inline int C(int n, int m) { // C_{n}^{m}
    return 1ll * fac[n] * invfac[m] % mod * invfac[n - m] % mod;
}

void exgcd(int a, int b, int& x, int& y) {
    if (!b) x = 1, y = 0;
    else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}
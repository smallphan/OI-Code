#include <bits/stdc++.h>

#define int long long

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

int x, k, m, n;

inline int qpow(int, int, int);

signed main() {
    x = read(), k = read(), m = read(), n = read();
    printf("%lld\n", ((x + m * qpow(10, k, n)) % n));
    return 0;
}

inline int qpow(int n, int k, int mod) {
    int ans = 1;
    while (k) {
        if (k & 1) ans = ans * n % mod;
        k = k >> 1;
        n = n * n % mod;
    }
    return ans;
}
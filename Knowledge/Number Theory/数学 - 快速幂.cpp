#include <cstdio>

using namespace std;

typedef unsigned long long uli;
uli t, n, k, mod;

inline long long read();
inline uli qpow(uli, uli, uli);

int main() {
    t = read();
    while (t--) {
        n = read(), k = read(), mod = read();
        printf("%llu ^ %llu = %llu [mod %llu]\n", n, k, qpow(n, k, mod), mod);
    }
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline uli qpow(uli n, uli k, uli mod) {
    uli ans = 1;
    while (k) {
        if (k & 1) ans = (ans * n) % mod;
        k = k >> 1;
        n = (n * n) % mod;
    }
    return ans;
}
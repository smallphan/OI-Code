// math: a^{\phi(m)}\equiv1\;(mod\;p)
// math: a\times a^{\phi(m)-1}\equiv1\;(mod\;p)

#include <cstdio>

using namespace std;

typedef unsigned long long ull;
ull t, num, mod, ans;

inline long long read();
inline ull gcd(ull, ull);
ull phi(ull);
ull inverse(ull, ull);

int main() {
    t = read();
    while (t--) {
        num = read(), mod = read();
        if (gcd(num, mod) != 1) {
            printf("[wrong data]\n");
            t++;
            continue;
        }
        printf("[%llu's inverse] %llu [mod %llu]\n", num, inverse(num, mod), mod);
    }
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
inline ull gcd(ull fir, ull sec) {
    return sec ? gcd(sec, fir % sec) : fir;
}
ull phi(ull n) {
    if (n <= 2) return 1;
    ull ans = 0;
    for (ull i = 1; i <= n; i++) {
        if (gcd(i, n) == 1) ans++;
    }
    return ans;
}
ull inverse(ull num, ull mod) {
    ull ans = 1, index = phi(mod) - 1;
    while (index) {
        if (index & 1) ans = (ans * num) % mod;
        index = index >> 1;
        num = (num * num) % mod;
    }
    return ans;
}
// math: a^{p-1}\equiv1\;(mod\;p)
// math: a^{p-2}\times a\equiv1\;(mod\;p)

#include <cstdio>

using namespace std;

typedef unsigned long long ull;
ull t, num, mod;

inline long long read();
ull inverse(ull num, ull mod);
ull gcd(ull fir, ull sec);

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
    return 0;
}

inline long long read() {
    long long ans = 0, flag = 1; char str = getchar();
    while (str < '0' || str > '9') { if (str == '-') flag = -1; str = getchar(); }
    while (str >= '0' && str <= '9') { ans = (ans << 3) + (ans << 1) + str - '0'; str = getchar(); }
    return ans * flag;
}
ull inverse(ull num, ull mod) {
    ull ans = 1, index = mod - 2;
    num %= mod;
    while (index) {
        if (index & 1) ans = (ans * num) % mod;
        index = index >> 1;
        num = (num * num) % mod;
    }
    return ans;
}
ull gcd(ull fir, ull sec) {
    return sec ? gcd(sec, fir % sec) : fir;
}
#include <cstdio>

using namespace std;

typedef unsigned long long ull;
ull t, num, mod, x, y;

inline long long read();
inline ull gcd(ull, ull);
inline void exgcd(ull, ull, ull&, ull&);

int main() {
    t = read();
    while (t--) {
        x = y = 0;
        num = read(), mod = read();
        if (gcd(num, mod) != 1) {
            printf("[wrong data]\n");
            t++;
            continue;
        }
        exgcd(num, mod, x, y);
        while (x < 0) x += mod;
        x %= mod;
        printf("[%llu's inverse] %llu [mod %llu]\n", num, x, mod);
    }
    return 0;
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
inline void exgcd(ull fir, ull sec, ull& x, ull& y) {
    if (!sec) {
        x = 1;
        y = 0;
        return;
    } else {
        exgcd(sec, fir % sec, x, y);
        ull num = x;
        x = y;
        y = num - (fir / sec) * y;
    }
}
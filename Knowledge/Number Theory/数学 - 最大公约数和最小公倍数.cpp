#include <cstdio>

using namespace std;

typedef unsigned long long ull;
ull t, fir, sec;

inline long long read();
inline ull gcd(ull, ull);
inline ull lcm(ull, ull);

int main() {
    t = read();
    for (int i = 1; i <= t; i++) {
        fir = read(), sec = read();
        printf("case %d :\n", i);
        printf("gcd(%llu,%llu) = %llu\n", fir, sec, gcd(fir, sec));
        printf("lcm(%llu,%llu) = %llu\n", fir, sec, lcm(fir, sec));
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
inline ull lcm(ull fir, ull sec) {
    return (fir * sec) / gcd(fir, sec);
}